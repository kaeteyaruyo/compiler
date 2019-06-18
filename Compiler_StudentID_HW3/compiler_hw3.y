%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int scope;
    int index;
	char *name;
	char *entry_type;
	char *data_type;
	char *parameter;
} symbol;

symbol *table[50][50];
int symbolCount[50] = { 0 };
int currentScope = 0;
int errorFlag = 0;
char errorMsg[256] = "";
FILE *file;

extern int yylineno;
extern int yylex();
extern char* yytext;
extern char buf[256];
void yyerror(char *s);

void create_symbol_variable(int scope, char *name, char *type);
void create_symbol_function(char *name, char *return_type, char *parameter_type);
symbol *lookup_symbol(char *name, int scope);
void dump_symbol(int scope);

void gencode_global_variable(char *name, char *type, char *initial_value);
void gencode_function(char *name, char *return_type, char *parameter_type);
void gencode_load_store(const char *instruction, const char *type, int index);
void gencode_arithmetic(const char *instruction, const char *type);
const char *get_type_descriptors(char *type);
const char *get_type_initial_value(char *type);

%}

%union {
    struct{
        char *type;
        char *value;
    } token;
    char *string;
};

%token IF ELSE FOR WHILE RETURN PRINT
%token GE_OP LE_OP EQ_OP NE_OP AND_OP OR_OP INC_OP DEC_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token <string> VOID INT FLOAT STRING BOOL ID
%token <token> I_CONST F_CONST STRING_LITERAL TRUE FALSE
%type <string> parameter_list type_specifier argument_expression_list
%type <token> expression assignment_expression relational_expression additive_expression
%type <token> multiplicative_expression unary_expression postfix_expression constant

%start translation_unit

%%

translation_unit:
	external_declaration                  {  }
	|
	translation_unit external_declaration {  }
	;

external_declaration:
	type_specifier ID '=' constant ';'     { // global variable declaration with initial value
        create_symbol_variable(0, $2, $1);
        gencode_global_variable($2, $1, $4.value);
    }
	|
	type_specifier ID ';'                  { // global variable declaration
        create_symbol_variable(0, $2, $1);
        gencode_global_variable($2, $1, "");
    }
	|
	function_declaration ';' 	           { // function declaration

    }
	|
	function_definition compound_statement { // (end of) function definition
        fprintf(file, ".end method\n");
    }
	;

function_declaration:
	type_specifier ID '(' ')'	             {
        if(lookup_symbol($2, 0)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared function %s", $2);
        }
        else{
            create_symbol_function($2, $1, "");
        }
    }
    |
	type_specifier ID '(' parameter_list ')' {
        if(lookup_symbol($2, 0)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared function %s", $2);
        }
        else{
            create_symbol_function($2, $1, $4);
        }
    }
    ;

function_definition:
	type_specifier ID '(' ')'	             {
        if(!lookup_symbol($2, 0)){
            create_symbol_function($2, $1, "");
        }
        gencode_function($2, $1, "");
    }
    |
	type_specifier ID '(' parameter_list ')' {
        if(!lookup_symbol($2, 0)){
            create_symbol_function($2, $1, $4);
        }
        gencode_function($2, $1, $4);
    }
    ;

type_specifier:
	VOID   {  }
	|
	INT    {  }
	|
	FLOAT  {  }
	|
	STRING {  }
	|
	BOOL   {  }
	;

parameter_list:
    type_specifier ID					 {
        create_symbol_variable(1, $2, $1);
        sprintf($$, "%s", get_type_descriptors($1));
    }
	|
	parameter_list ',' type_specifier ID {
        create_symbol_variable(1, $4, $3);
        sprintf($$, "%s%s", $1, get_type_descriptors($3));
    }
	;

compound_statement:
	'{' '}'				   	{  }
	|
    '{' block_item_list '}'	{  }
	;

block_item_list:
	block_item					{  }
	|
    block_item_list block_item	{  }
	;

block_item:
	type_specifier ID ';'                           {
        create_symbol_variable(currentScope, $2, $1);
        fprintf(file, "\tldc %s\n", get_type_initial_value($1));
        gencode_load_store("store", $1, lookup_symbol($2, currentScope)->index);
    }
    |
	type_specifier ID '=' additive_expression ';' {
        create_symbol_variable(currentScope, $2, $1);
        if(!strcmp($1, "int") && !strcmp($4.type, "float")){
            fprintf(file, "\tf2i\n");
        }
        else if(!strcmp($1, "float") && !strcmp($4.type, "int")){
            fprintf(file, "\ti2f\n");
        }
        gencode_load_store("store", $1, lookup_symbol($2, currentScope)->index);
    }
	|
    statement              	                        {  }
	;

expression:
	assignment_expression {  }
	;

assignment_expression:
	ID '=' additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
	|
	ID ADD_ASSIGN additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
        }
    }
	|
	ID SUB_ASSIGN additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
	|
	ID MUL_ASSIGN additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
	|
	ID DIV_ASSIGN additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
	|
	ID MOD_ASSIGN additive_expression {
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            gencode_load_store("store", variable->data_type, variable->index);
        }
    }
	;

additive_expression:
	multiplicative_expression							{  }
	|
    additive_expression '+' multiplicative_expression	{
        fprintf(file, "%s(%s) + %s(%s)\n", $1.value, $1.type, $3.value, $3.type);
        if(!strcmp($1.type, "int") && !strcmp($3.type, "int")){
            sprintf($$.type, "int");
            sprintf($$.value, "%d", atoi($1.value) + atoi($3.value));
            gencode_arithmetic("add", "int");
        }
        else{
            if(!strcmp($1.type, "float") && !strcmp($3.type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp($1.type, "int") && !strcmp($3.type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf($$.type, "float");
            gencode_arithmetic("add", "float");
        }
    }
	|
    additive_expression '-' multiplicative_expression	{
        fprintf(file, "%s(%s) - %s(%s)\n", $1.value, $1.type, $3.value, $3.type);
        if(!strcmp($1.type, "int") && !strcmp($3.type, "int")){
            sprintf($$.type, "int");
            sprintf($$.value, "%d", atoi($1.value) - atoi($3.value));
            gencode_arithmetic("sub", "int");
        }
        else{
            if(!strcmp($1.type, "float") && !strcmp($3.type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp($1.type, "int") && !strcmp($3.type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf($$.type, "float");
            gencode_arithmetic("sub", "float");
        }
    }
	;

multiplicative_expression:
	unary_expression								{  }
	|
    multiplicative_expression '*' unary_expression {
        fprintf(file, "%s(%s) * %s(%s)\n", $1.value, $1.type, $3.value, $3.type);
        if(!strcmp($1.type, "int") && !strcmp($3.type, "int")){
            sprintf($$.type, "int");
            sprintf($$.value, "%d", atoi($1.value) * atoi($3.value));
            gencode_arithmetic("mul", "int");
        }
        else{
            if(!strcmp($1.type, "float") && !strcmp($3.type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp($1.type, "int") && !strcmp($3.type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
            }
            sprintf($$.type, "float");
            gencode_arithmetic("mul", "float");
        }
    }
	|
    multiplicative_expression '/' unary_expression {
        fprintf(file, "%s(%s) / %s(%s)\n", $1.value, $1.type, $3.value, $3.type);
        if(!strcmp($3.value, "0") || !strcmp($3.value, "0.0")){
            errorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            if(!strcmp($1.type, "int") && !strcmp($3.type, "int")){
                sprintf($$.type, "int");
                sprintf($$.value, "%d", atoi($1.value) / atoi($3.value));
                gencode_arithmetic("div", "int");
            }
            else{
                if(!strcmp($1.type, "float") && !strcmp($3.type, "int")){
                    fprintf(file, "\ti2f\n");
                }
                else if(!strcmp($1.type, "int") && !strcmp($3.type, "float")){
                    fprintf(file, "\tswap\n");
                    fprintf(file, "\ti2f\n");
                }
                sprintf($$.type, "float");
                gencode_arithmetic("div", "float");
            }
        }
    }
	|
    multiplicative_expression '%' unary_expression {
        if(!strcmp($3.value, "0") || !strcmp($3.value, "0.0")){
            errorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            if(!strcmp($1.type, "int") && !strcmp($3.type, "int")){
                sprintf($$.type, "int");
                gencode_arithmetic("rem", "int");
            }
            else{
                errorFlag = 1;
                sprintf(errorMsg, "Modulo operator with floating point operands");
            }
        }
    }
	;

unary_expression:
	postfix_expression		{  }
	|
	'+' unary_expression	{  }
	|
	'-' unary_expression	{  }
	;

postfix_expression:
	ID					{ // variable at RHS
        symbol *variable = NULL;
        int i;
        for(i = currentScope; i >= 0; --i){
            variable = lookup_symbol($1, i);
            if(variable) break;
        }
        if(!variable){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
        else{
            sprintf($$.type, "%s", variable->data_type);
            sprintf($$.value, "%s", variable->name);
            if(i == 0)
                fprintf(file, "\tgetstatic compiler_hw3/%s %s\n", variable->name, get_type_descriptors(variable->data_type));
            else
                gencode_load_store("load", variable->data_type, variable->index);
        }
    }
	|
	constant {
        fprintf(file, "\tldc %s\n", $1.value);
    }
	|
	ID INC_OP {  }
	|
	ID DEC_OP {  }
    |
	ID '(' ')' { // function call
        symbol *function = lookup_symbol($1, 0);
        if(!function){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
        }
        else{
            sprintf($$.type, "%s", function->data_type);
            sprintf($$.value, "%s", function->name);
            fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", function->name, get_type_descriptors(function->data_type));
        }
    }
	|
	ID '(' argument_expression_list ')'	{ // function call with argument
        symbol *function = lookup_symbol($1, 0);
        if(!function){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
        }
        else{
            if(strcmp($3, function->parameter)){
                errorFlag = 1;
                sprintf(errorMsg, "Function formal parameter is not the same");
            }
            else{
                sprintf($$.type, "%s", function->data_type);
                sprintf($$.value, "%s", function->name);
                fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", function->name, function->parameter, get_type_descriptors(function->data_type));
            }
        }
    }
	|
	'(' additive_expression ')'	{
        fprintf(file, "( %s(%s) )\n", $2.value, $2.type);
    }
	;

argument_expression_list:
	postfix_expression {
        sprintf($$, "%s", get_type_descriptors($1.type));
    }
	|
    argument_expression_list ',' postfix_expression {
        sprintf($$, "%s%s", $1, get_type_descriptors($3.type));
    }
	;

constant:
	I_CONST		    {  }
	|
	F_CONST		    {  }
	|
	TRUE		    {  }
	|
	FALSE		   	{  }
	|
	STRING_LITERAL	{  }
	;

statement:
	compound_statement	 {  }
	|
    expression_statement {  }
	|
    selection_statement	 {  }
	|
    iteration_statement  {  }
	|
    return_statement     {  }
	|
    print_statement	     {  }
	;

expression_statement:
	';'			   {  }
	|
    expression ';' {  }
	;

selection_statement:
	IF '(' relational_expression ')' statement %prec LOWER_THAN_ELSE {  }
	|
    IF '(' relational_expression ')' statement ELSE statement        {  }
	;

iteration_statement:
	WHILE '(' relational_expression ')' statement {  }
	;

relational_expression:
    postfix_expression EQ_OP postfix_expression	{  }
	|
    postfix_expression NE_OP postfix_expression	{  }
	|
    postfix_expression '<' postfix_expression	{  }
	|
    postfix_expression '>' postfix_expression	{  }
	|
    postfix_expression LE_OP postfix_expression	{  }
	|
    postfix_expression GE_OP postfix_expression	{  }
	;

return_statement:
	RETURN ';'          {
        char *return_type = table[0][symbolCount[0] - 1]->data_type;
        if(!strcmp(return_type, "void")){
            fprintf(file, "\treturn\n");
        }
        else{
            errorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
	|
    RETURN postfix_expression ';'       {
        char *return_type = table[0][symbolCount[0] - 1]->data_type;
        if(!strcmp(return_type, $2.type)){
            if(!strcmp(return_type, "int") || !strcmp(return_type, "bool")){
                fprintf(file, "\tireturn\n");
            }
            else if(!strcmp(return_type, "float")){
                fprintf(file, "\tfreturn\n");
            }
        }
        else{
            errorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
	;

print_statement:
	PRINT '(' postfix_expression ')' ';' {
        fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        fprintf(file, "\tswap\n");
        fprintf(file, "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_type_descriptors($3.type));
    }
	;

%%

/* C code section */
int main(int argc, char **argv)
{
    yylineno = 0;

    file = fopen("compiler_hw3.j", "w");
    fprintf(file, ".class public compiler_hw3\n"
                  ".super java/lang/Object\n");

    yyparse();

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
    if(!strcmp(s, "syntax error")){
        if(strlen(buf) != 0){
            printf("%d: %s\n", yylineno + 1, buf);
        }
        else{
            printf("%d:\n", yylineno + 1);
        }
        if(errorFlag > 0){
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", errorMsg);
            printf("\n|-----------------------------------------------|\n\n");
            errorFlag = 0;
        }
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno + 1, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
    else{
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");

    }
}

void create_symbol_variable(int scope, char *name, char *type){
    if(lookup_symbol(name, scope)){
        errorFlag = 1;
        sprintf(errorMsg, "Redeclared variable %s", name);
        return;
    }

    symbol *tmp = malloc(sizeof(symbol));
    tmp->name = strdup(name);
    tmp->entry_type = strdup("variable");
    tmp->data_type = strdup(type);
    tmp->scope = scope;
    tmp->parameter = strdup("");
    tmp->index = symbolCount[scope];
    for(int i = 1; i < scope; ++i)
        tmp->index += symbolCount[i];
    table[scope][symbolCount[scope]++] = tmp;
}

void create_symbol_function(char *name, char *return_type, char *parameter_type){
    symbol *tmp = malloc(sizeof(symbol));
    tmp->name = strdup(name);
    tmp->entry_type = strdup("function");
    tmp->data_type = strdup(return_type);
    tmp->scope = 0;
    tmp->parameter = strdup(parameter_type);
    tmp->index = symbolCount[0]++;
    table[0][tmp->index] = tmp;
}

symbol *lookup_symbol(char *name, int scope){
    for(int i = 0; i < symbolCount[scope]; ++i){
        if(!strcmp(table[scope][i]->name, name))
            return table[scope][i];
    }
    return NULL;
}

void dump_symbol(int scope) {
    if(symbolCount[scope] > 0){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n", "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        for(int i = 0; i < symbolCount[scope]; ++i){
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", i, table[scope][i]->name, table[scope][i]->entry_type, table[scope][i]->data_type, table[scope][i]->scope, table[scope][i]->parameter);
        }
        printf("\n");
        for(int i = 0; i < symbolCount[scope]; ++i){
            free(table[scope][i]);
            table[scope][i] = NULL;
        }
        symbolCount[scope] = 0;
    }
}

void gencode_global_variable(char *name, char *type, char *initial_value) {
    if(strcmp(initial_value, "")){
        fprintf(file, ".field public static %s %s = %s\n", name, get_type_descriptors(type), initial_value);
    }
    else
        fprintf(file, ".field public static %s %s\n", name, get_type_descriptors(type));
}

void gencode_function(char *name, char *return_type, char *parameter_type){
    if(!strcmp(name, "main"))
        fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
    else
        fprintf(file, ".method public static %s(%s)%s\n", name, parameter_type, get_type_descriptors(return_type));
    fprintf(file, ".limit stack 50\n");
    fprintf(file, ".limit locals 50\n");
}

void gencode_load_store(const char *instruction, const char *type, int index){
    if(!strcmp(instruction, "store")){
        if(!strcmp(type, "int") || !strcmp(type, "bool"))
            fprintf(file, "\tistore %d\n", index);
        else if(!strcmp(type, "float"))
            fprintf(file, "\tfstore %d\n", index);
        else if(!strcmp(type, "string"))
            fprintf(file, "\tastore %d\n", index);
    }
    else if(!strcmp(instruction, "load")){
        if(!strcmp(type, "int") || !strcmp(type, "bool"))
            fprintf(file, "\tiload %d\n", index);
        else if(!strcmp(type, "float"))
            fprintf(file, "\tfload %d\n", index);
        else if(!strcmp(type, "string"))
            fprintf(file, "\taload %d\n", index);
    }
}

void gencode_arithmetic(const char *instruction, const char *type){
    if(!strcmp(instruction, "add")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tiadd\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfadd\n");
        }
    }
    else if(!strcmp(instruction, "sub")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tisub\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfsub\n");
        }
    }
    else if(!strcmp(instruction, "mul")){
        if(!strcmp(type, "int")){
            fprintf(file, "\timul\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfmul\n");
        }
    }
    else if(!strcmp(instruction, "div")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tidiv\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfdiv\n");
        }
    }
    else if(!strcmp(instruction, "rem")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tirem\n");
        }
    }
    else if(!strcmp(instruction, "neg")){
        if(!strcmp(type, "int")){
            fprintf(file, "\tineg\n");
        }
        else if(!strcmp(type, "float")){
            fprintf(file, "\tfneg\n");
        }
    }
}

const char *get_type_descriptors(char *type){
    if(!strcmp(type, "int"))
        return "I";
    else if(!strcmp(type, "bool"))
        return "Z";
    else if(!strcmp(type, "float"))
        return "F";
    else if(!strcmp(type, "void"))
        return "V";
    else if(!strcmp(type, "string"))
        return "Ljava/lang/String;";
}

const char *get_type_initial_value(char *type){
    if(!strcmp(type, "int"))
        return "0";
    else if(!strcmp(type, "bool"))
        return "0";
    else if(!strcmp(type, "float"))
        return "0.0";
}
