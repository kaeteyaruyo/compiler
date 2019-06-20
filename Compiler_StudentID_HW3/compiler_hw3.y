%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int scope;
    int index;
    int defined;
	char *name;
	char *entry_type;
	char *data_type;
	char *parameter;
} symbol;

symbol *table[50][50];
int symbolCount[50] = { 0 };
int ifCount = 0;
int whileCount = 0;
int currentScope = 0;
int semanticErrorFlag = 0;
int saveFileFlag = 1;
char errorMsg[256] = "";
FILE *file;

extern int yylineno;
extern int yylex();
extern char* yytext;
extern char buf[256];
void yyerror(const char *s);

void create_symbol_variable(int scope, const char *name, const char *type);
void create_symbol_function(const char *name, const char *return_type, const char *parameter_type, int defined);
symbol *lookup_symbol_with_scope(const char *name, int scope);
symbol *lookup_symbol(const char *name);
void dump_symbol(int scope);

void gencode_global_variable(const char *instruction, const char *name, const char *type, const char *initial_value);
void gencode_function(const char *name, const char *return_type, const char *parameter_type);
void gencode_assignment(const char *name, const char *instruction, char *right_type);
void gencode_load_store(const char *instruction, int index, const char *type);
void gencode_arithmetic(const char *instruction, const char *type);
const char *gencode_expression(const char *instruction, const char *left_type, const char *right_type);
const char *get_type_descriptors(const char *type);
const char *get_type_initial_value(const char *type);

%}

%union {
    struct{
        char type[10];
        char value[64];
    } token;
    char string[64];
    int labelIndex;
};

%token IF ELSE WHILE RETURN PRINT
%token GE_OP LE_OP EQ_OP NE_OP AND_OP OR_OP INC_OP DEC_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token <string> VOID INT FLOAT STRING BOOL ID
%token <token> I_CONST F_CONST STRING_LITERAL TRUE FALSE
%type <string> parameter_list type_specifier argument_expression_list
%type <token> constant assignment_expression relational_expression
%type <token> additive_expression multiplicative_expression postfix_expression
%type <labelIndex> while while_condition if_condition if_else_condition

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
        gencode_global_variable("declare", $2, $1, $4.value);
    }
	|
	type_specifier ID ';'                  { // global variable declaration
        create_symbol_variable(0, $2, $1);
        gencode_global_variable("declare", $2, $1, "");
    }
	|
	function_declaration ';' 	           { // function declaration

    }
	|
	function_definition compound_statement { //  function definition
        fprintf(file, ".end method\n");
    }
	;

function_declaration:
	type_specifier ID '(' ')' { // function declaration
        symbol *function = lookup_symbol_with_scope($2, 0);
        if(!function){
            // Not declared or defined yet
            create_symbol_function($2, $1, "", 0);
        }
        else{
            // Redeclared error
            if(!function->defined){
                semanticErrorFlag = 1;
                sprintf(errorMsg, "Redeclared function %s", $2);
            }
            // Else, define then declare
            else{
                if(strcmp(function->parameter, "") && strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "1. Function return type is not the same\n| 2. Function formal parameter is not the same");
                }
                else if(strcmp(function->parameter, "")){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function formal parameter is not the same");
                }
                else if(strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function return type is not the same");
                }
            }
        }
        for(int i = 0; i < symbolCount[1]; ++i){
            free(table[1][i]);
            table[1][i] = NULL;
        }
        symbolCount[1] = 0;
    }
    |
	type_specifier ID '(' parameter_list ')' { // function declaration with parameter
        symbol *function = lookup_symbol_with_scope($2, 0);
        if(!function){
            // Not declared or defined yet
            create_symbol_function($2, $1, $4, 0);
        }
        else{
            // Redeclared error
            if(!function->defined){
                semanticErrorFlag = 1;
                sprintf(errorMsg, "Redeclared function %s", $2);
            }
            // Else, define then declare
            else{
                if(strcmp(function->parameter, $4) && strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "1. Function return type is not the same\n| 2. Function formal parameter is not the same");
                }
                else if(strcmp(function->parameter, $4)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function formal parameter is not the same");
                }
                else if(strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function return type is not the same");
                }
            }
        }
        for(int i = 0; i < symbolCount[1]; ++i){
            free(table[1][i]);
            table[1][i] = NULL;
        }
        symbolCount[1] = 0;
    }
    ;

function_definition:
	type_specifier ID '(' ')'	             { // function definition
        symbol *function = lookup_symbol_with_scope($2, 0);
        if(!function){
            // Not declared or defined yet
            create_symbol_function($2, $1, "", 1);
            gencode_function($2, $1, "");
        }
        else{
            // Declared but not defined yet
            if(!function->defined){
                if(strcmp(function->parameter, "") && strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "1. Function return type is not the same\n| 2. Function formal parameter is not the same");
                }
                else if(strcmp(function->parameter, "")){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function formal parameter is not the same");
                }
                else if(strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function return type is not the same");
                }
                else{
                    gencode_function($2, $1, "");
                }
            }
        }
    }
    |
	type_specifier ID '(' parameter_list ')' { // function declaration with parameter
        symbol *function = lookup_symbol_with_scope($2, 0);
        if(!function){
            // Not declared or defined yet
            create_symbol_function($2, $1, $4, 1);
            gencode_function($2, $1, $4);
        }
        else{
            // Declared but not defined yet
            if(!function->defined){
                if(strcmp(function->parameter, $4) && strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "1. Function return type is not the same\n| 2. Function formal parameter is not the same");
                }
                else if(strcmp(function->parameter, $4)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function formal parameter is not the same");
                }
                else if(strcmp(function->data_type, $1)){
                    semanticErrorFlag = 1;
                    sprintf(errorMsg, "Function return type is not the same");
                }
                else{
                    gencode_function($2, $1, $4);
                }
            }
        }
    }
    ;

parameter_list:
    type_specifier ID					 { // parameter
        create_symbol_variable(1, $2, $1);
        sprintf($$, "%s", get_type_descriptors($1));
    }
	|
	parameter_list ',' type_specifier ID { // parameter list
        create_symbol_variable(1, $4, $3);
        sprintf($$, "%s%s", $1, get_type_descriptors($3));
    }
	;

statement:
	compound_statement	 {  }
	|
    expression_statement {  }
	|
    if_condition statement %prec LOWER_THAN_ELSE {
        fprintf(file, "IF_FALSE_%d:\n", $1);
    }
	|
    if_else_condition statement{
        fprintf(file, "IF_EXIT_%d:\n", $1);
    }
	|
    while_condition statement {
        fprintf(file, "\tgoto WHILE_BEGIN_%d\n", $1);
        fprintf(file, "WHILE_END_%d:\n", $1);
    }
	|
    return_statement     {  }
	|
    print_statement	     {  }
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
	type_specifier ID ';' { // local variable declaration
        create_symbol_variable(currentScope, $2, $1);
        if(!semanticErrorFlag){
            fprintf(file, "\tldc %s\n", get_type_initial_value($1));
            gencode_load_store("store", lookup_symbol_with_scope($2, currentScope)->index, $1);
        }
    }
    |
	type_specifier ID '=' additive_expression ';' { // local variable declaration with initial value
        if(!semanticErrorFlag){
            create_symbol_variable(currentScope, $2, $1);
            if(!semanticErrorFlag){
                gencode_assignment($2, "", $4.type);
            }
        }
    }
	|
    statement {  }
	;

expression_statement:
	';'			   {  }
	|
    assignment_expression ';' {  }
	;

assignment_expression:
    additive_expression               { // do some caculation but not stored
        fprintf(file, "\tpop\n");
    }
    |
	ID '=' additive_expression        { // assign
        gencode_assignment($1, "", $3.type);
    }
	|
	ID ADD_ASSIGN additive_expression { // add then assign
        gencode_assignment($1, "add", $3.type);
    }
	|
	ID SUB_ASSIGN additive_expression { // subtract then assign
        gencode_assignment($1, "sub", $3.type);
    }
	|
	ID MUL_ASSIGN additive_expression { // multiply then assign
        gencode_assignment($1, "mul", $3.type);
    }
	|
	ID DIV_ASSIGN additive_expression { // divide then assign
        if(!strcmp($3.value, "0") || !strcmp($3.value, "0.0")){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            gencode_assignment($1, "div", $3.type);
        }
    }
	|
	ID MOD_ASSIGN additive_expression { // modulo then assign
        if(!strcmp($3.value, "0")){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            gencode_assignment($1, "rem", $3.type);
        }
    }
	;

additive_expression:
	multiplicative_expression							{  }
	|
    additive_expression '+' multiplicative_expression	{ // add
        sprintf($$.type, "%s", gencode_expression("add", $1.type, $3.type));
    }
	|
    additive_expression '-' multiplicative_expression	{ // subtract
        sprintf($$.type, "%s", gencode_expression("sub", $1.type, $3.type));
    }
	;

multiplicative_expression:
	postfix_expression								{  }
	|
    multiplicative_expression '*' postfix_expression { // multiply
        sprintf($$.type, "%s", gencode_expression("mul", $1.type, $3.type));
    }
	|
    multiplicative_expression '/' postfix_expression { // divide
        if(!strcmp($3.value, "0") || !strcmp($3.value, "0.0")){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            sprintf($$.type, "%s", gencode_expression("div", $1.type, $3.type));
        }
    }
	|
    multiplicative_expression '%' postfix_expression { // modulo
        if(!strcmp($3.value, "0")){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Divided by zero");
        }
        else{
            sprintf($$.type, "%s", gencode_expression("rem", $1.type, $3.type));
        }
    }
	;

postfix_expression:
	ID { // variable at RHS
        symbol *variable = lookup_symbol($1);
        if(variable){
            sprintf($$.type, "%s", variable->data_type);
            sprintf($$.value, "%s", variable->name);
            if(variable->scope == 0){
                gencode_global_variable("load", variable->name, variable->data_type, "");
            }
            else{
                gencode_load_store("load", variable->index, variable->data_type);
            }
        }
        else{
            memset($$.type, 0, 10);
            memset($$.value, 0, 64);
        }
    }
	|
	constant { // constant
        fprintf(file, "\tldc %s\n", $1.value);
    }
	|
	ID INC_OP { // postfix increment
        symbol *variable = lookup_symbol($1);
        if(variable){
            sprintf($$.type, "%s", variable->data_type);
            sprintf($$.value, "%s", variable->name);
            if(variable->scope == 0){
                gencode_global_variable("load", variable->name, variable->data_type, "");
                gencode_global_variable("load", variable->name, variable->data_type, "");
                fprintf(file, "\tldc 1\n");
                fprintf(file, "\tiadd\n");
                gencode_global_variable("store", variable->name, variable->data_type, "");
            }
            else{
                gencode_load_store("load", variable->index, variable->data_type);
                gencode_load_store("load", variable->index, variable->data_type);
                fprintf(file, "\tldc 1\n");
                fprintf(file, "\tiadd\n");
                gencode_load_store("store", variable->index, variable->data_type);
            }
        }
        else{
            memset($$.type, 0, 10);
            memset($$.value, 0, 64);
        }

    }
	|
	ID DEC_OP {
        symbol *variable = lookup_symbol($1);
        if(variable){
            sprintf($$.type, "%s", variable->data_type);
            sprintf($$.value, "%s", variable->name);
            if(variable->scope == 0){
                gencode_global_variable("load", variable->name, variable->data_type, "");
                gencode_global_variable("load", variable->name, variable->data_type, "");
                fprintf(file, "\tldc 1\n");
                fprintf(file, "\tisub\n");
                gencode_global_variable("store", variable->name, variable->data_type, "");
            }
            else{
                gencode_load_store("load", variable->index, variable->data_type);
                gencode_load_store("load", variable->index, variable->data_type);
                fprintf(file, "\tldc 1\n");
                fprintf(file, "\tisub\n");
                gencode_load_store("store", variable->index, variable->data_type);
            }
        }
        else{
            memset($$.type, 0, 10);
            memset($$.value, 0, 64);
        }
    }
    |
	ID '(' ')' { // function call
        symbol *function = lookup_symbol_with_scope($1, 0);
        if(!function){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
            memset($$.type, 0, 10);
            memset($$.value, 0, 64);
        }
        else{
            if(strcmp(function->parameter, "")){
                semanticErrorFlag = 1;
                sprintf(errorMsg, "Function formal parameter is not the same");
                memset($$.type, 0, 10);
                memset($$.value, 0, 64);
            }
            else{
                sprintf($$.type, "%s", function->data_type);
                sprintf($$.value, "%s", function->name);
                fprintf(file, "\tinvokestatic compiler_hw3/%s()%s\n", function->name, get_type_descriptors(function->data_type));
            }
        }
    }
	|
	ID '(' argument_expression_list ')'	{ // function call with argument
        symbol *function = lookup_symbol_with_scope($1, 0);
        if(!function){
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
            memset($$.type, 0, 10);
            memset($$.value, 0, 64);
        }
        else{
            if(strcmp(function->parameter, $3)){
                semanticErrorFlag = 1;
                sprintf(errorMsg, "Function formal parameter is not the same");
                memset($$.type, 0, 10);
                memset($$.value, 0, 64);
            }
            else{
                sprintf($$.type, "%s", function->data_type);
                sprintf($$.value, "%s", function->name);
                fprintf(file, "\tinvokestatic compiler_hw3/%s(%s)%s\n", function->name, function->parameter, get_type_descriptors(function->data_type));
            }
        }
    }
	|
	'(' additive_expression ')'	{ // bracketed expression
        $$ = $2;
    }
	;

argument_expression_list:
	postfix_expression {
        if(strcmp($1.type, "")){
            sprintf($$, "%s", get_type_descriptors($1.type));
        }
        else{
            sprintf($$, "V");
        }
    }
	|
    argument_expression_list ',' postfix_expression {
        if(strcmp($3.type, "")){
            sprintf($$, "%s%s", $1, get_type_descriptors($3.type));
        }
        else{
            sprintf($$, "%sV", $1);
        }
    }
	;

if_else_condition:
    if_condition statement ELSE {
        fprintf(file, "\tgoto IF_EXIT_%d\n", $1);
        fprintf(file, "IF_FALSE_%d:\n", $1);
    }
	;

if_condition:
    IF '(' relational_expression ')' {
        int ifIndex = ++ifCount;
        fprintf(file, "IF_TRUE_%d\n", ifIndex);
        fprintf(file, "\tgoto IF_FALSE_%d\n", ifIndex);
        fprintf(file, "IF_TRUE_%d:\n", ifIndex);
        $$ = ifIndex;
    }
    ;

while_condition:
	while '(' relational_expression ')' {
        fprintf(file, "WHILE_BODY_%d\n", $1);
        fprintf(file, "\tgoto WHILE_END_%d\n", $1);
        fprintf(file, "WHILE_BODY_%d:\n", $1);
    }
	;

while:
    WHILE {
        int whileIndex = ++whileCount;
        fprintf(file, "WHILE_BEGIN_%d:\n", whileIndex);
        $$ = whileIndex;
    }
    ;

relational_expression:
    postfix_expression EQ_OP postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tifeq ");
        }
    }
	|
    postfix_expression NE_OP postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tifne ");
        }
    }
	|
    postfix_expression '<' postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tiflt ");
        }
    }
	|
    postfix_expression '>' postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tifgt ");
        }
    }
	|
    postfix_expression LE_OP postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tifle ");
        }
    }
	|
    postfix_expression GE_OP postfix_expression	{
        if(strcmp($1.type, "") && strcmp($3.type, "")){
            if(!strcmp(gencode_expression("sub", $1.type, $3.type), "float")){
                fprintf(file, "\tf2i\n");
            }
            fprintf(file, "\tifge ");
        }
    }
	;

return_statement:
	RETURN ';'          {
        if(!strcmp(table[0][symbolCount[0] - 1]->data_type, "void")){
            fprintf(file, "\treturn\n");
        }
        else{
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
	|
    RETURN postfix_expression ';'       {
        const char *return_type = table[0][symbolCount[0] - 1]->data_type;
        if(strcmp($2.type, "") && !strcmp(return_type, $2.type)){
            if(!strcmp(return_type, "int") || !strcmp(return_type, "bool")){
                fprintf(file, "\tireturn\n");
            }
            else if(!strcmp(return_type, "float")){
                fprintf(file, "\tfreturn\n");
            }
        }
        else{
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Function return type is not the same");
        }
    }
	;

print_statement:
	PRINT '(' postfix_expression ')' ';' {
        if(strcmp($3.type, ""))
        {
            fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "\tswap\n");
            fprintf(file, "\tinvokevirtual java/io/PrintStream/println(%s)V\n", get_type_descriptors($3.type));
        }
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
    if(!saveFileFlag){
        remove("compiler_hw3.j");
    }

    return 0;
}

void yyerror(const char *s)
{
    // If the error is syntax error
    if(!strcmp(s, "syntax error")){
        // Flush error code line if any
        if(strlen(buf) != 0){
            printf("%d: %s\n", yylineno + 1, buf);
        }
        // If not, print line number only
        else{
            printf("%d:\n", yylineno + 1);
        }

        // If there is also a semantic error, print it too
        if(semanticErrorFlag > 0){
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", errorMsg);
            printf("\n|-----------------------------------------------|\n\n");
            semanticErrorFlag = 0;
        }

        // Print syntax error message
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno + 1, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
    // If the error is semantic error
    else{
        // Don't generate (save) file if semantic error occur
        saveFileFlag = 0;

        // Print semantic error message
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");

    }
}

void create_symbol_variable(int scope, const char *name, const char *type){
    if(lookup_symbol_with_scope(name, scope)){
        semanticErrorFlag = 1;
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
    tmp->defined = 1;
    table[scope][symbolCount[scope]++] = tmp;
}

void create_symbol_function(const char *name, const char *return_type, const char *parameter_type, int defined){
    symbol *tmp = malloc(sizeof(symbol));
    tmp->name = strdup(name);
    tmp->entry_type = strdup("function");
    tmp->data_type = strdup(return_type);
    tmp->scope = 0;
    tmp->parameter = strdup(parameter_type);
    tmp->index = symbolCount[0]++;
    tmp->defined = defined;
    table[0][tmp->index] = tmp;
}

symbol *lookup_symbol_with_scope(const char *name, int scope){
    for(int i = 0; i < symbolCount[scope]; ++i){
        if(!strcmp(table[scope][i]->name, name))
            return table[scope][i];
    }
    return NULL;
}

symbol *lookup_symbol(const char *name){
    symbol *tmp = NULL;
    for(int i = currentScope; i >= 0; --i){
        tmp = lookup_symbol_with_scope(name, i);
        if(tmp) break;
    }
    if(!tmp){
        semanticErrorFlag = 1;
        sprintf(errorMsg, "Undeclared variable %s", name);
    }
    return tmp;
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

void gencode_global_variable(const char *instruction, const char *name, const char *type, const char *initial_value){
    if(!strcmp(instruction, "declare")){
        if(strcmp(initial_value, "")){
            fprintf(file, ".field public static %s %s = %s\n", name, get_type_descriptors(type), initial_value);
        }
        else{
            fprintf(file, ".field public static %s %s\n", name, get_type_descriptors(type));
        }
    }
    else if(!strcmp(instruction, "store")){
        fprintf(file, "\tputstatic compiler_hw3/%s %s\n", name, get_type_descriptors(type));
    }
    else if(!strcmp(instruction, "load")){
        fprintf(file, "\tgetstatic compiler_hw3/%s %s\n", name, get_type_descriptors(type));
    }
}

void gencode_function(const char *name, const char *return_type, const char *parameter_type){
    if(!strcmp(name, "main"))
        fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
    else
        fprintf(file, ".method public static %s(%s)%s\n", name, parameter_type, get_type_descriptors(return_type));
    fprintf(file, ".limit stack 50\n");
    fprintf(file, ".limit locals 50\n");
}

void gencode_load_store(const char *instruction, int index, const char *type){
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

void gencode_assignment(const char *name, const char *instruction, char *right_type){
    symbol *variable = lookup_symbol(name);
    if(variable){
        if(strcmp(instruction, "")){
            if(variable->scope == 0){
                gencode_global_variable("load", variable->name, variable->data_type, "");
            }
            else{
                gencode_load_store("load", variable->index, variable->data_type);
            }
            fprintf(file, "\tswap\n");
            right_type = strdup(gencode_expression(instruction, variable->data_type, right_type));
        }

        if(!strcmp(variable->data_type, "int") && !strcmp(right_type, "float")){
            fprintf(file, "\tf2i\n");
        }
        else if(!strcmp(variable->data_type, "float") && !strcmp(right_type, "int")){
            fprintf(file, "\ti2f\n");
        }

        if(variable->scope == 0){
            gencode_global_variable("store", variable->name, variable->data_type, "");
        }
        else{
            gencode_load_store("store", variable->index, variable->data_type);
        }
    }
}

const char *gencode_expression(const char *instruction, const char *left_type, const char *right_type){
    if(strcmp(instruction, "rem")){
        if(!strcmp(left_type, "int") && !strcmp(right_type, "int")){
            gencode_arithmetic(instruction, "int");
            return "int";
        }
        else{
            if(!strcmp(left_type, "float") && !strcmp(right_type, "int")){
                fprintf(file, "\ti2f\n");
            }
            else if(!strcmp(left_type, "int") && !strcmp(right_type, "float")){
                fprintf(file, "\tswap\n");
                fprintf(file, "\ti2f\n");
                fprintf(file, "\tswap\n");
            }
            gencode_arithmetic(instruction, "float");
            return "float";
        }
    }
    else{
        if(!strcmp(left_type, "int") && !strcmp(right_type, "int")){
            gencode_arithmetic("rem", "int");
            return "int";
        }
        else{
            semanticErrorFlag = 1;
            sprintf(errorMsg, "Modulo operator with floating point operands");
            return "";
        }
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

const char *get_type_descriptors(const char *type){
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

const char *get_type_initial_value(const char *type){
    if(!strcmp(type, "int"))
        return "0";
    else if(!strcmp(type, "bool"))
        return "0";
    else if(!strcmp(type, "float"))
        return "0.0";
}
