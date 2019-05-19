/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *name;
	char *entryType;
	char *dataType;
	int scope;
	char *parameter;
} symbol;

symbol *table[10][30];
int symbolCount[10] = { 0 };
int currentScope = 0;
int errorFlag = 0;
char errorMsg[256] = "";

extern int yylineno;
extern int yylex();
void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
void create_symbol(char *signature);
void insert_symbol(symbol *s);
int lookup_symbol(char *name, int scope);
void dump_symbol(int scope);
%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
	int boolean;
}

/* Token without return */
%token IF ELSE FOR WHILE RETURN PRINT
%token GE_OP LE_OP EQ_OP NE_OP AND_OP OR_OP INC_OP DEC_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <string> VOID INT FLOAT STRING BOOL

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING_LITERAL ID
%token <boolean> TRUE FALSE

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <string> variable_declaration function_declaration function_definition parameter_list parameter_declarator type_specifier

/* Yacc will start at this nonterminal */
%start translation_unit


%%

translation_unit:
	external_declaration			    	{  }
	|
	translation_unit external_declaration	{  }
	;

external_declaration:
	variable_declaration                    { create_symbol($1); }
	|
	function_declaration ';' 	            {  }
	|
	function_definition compound_statement 	{  }
	;

variable_declaration:
	type_specifier ID ';'                           { sprintf($$, "%s %s variable %d", $1, $2, currentScope); }
    |
	type_specifier ID '=' assignment_expression ';' { sprintf($$, "%s %s variable %d", $1, $2, currentScope); }
	;

function_declaration:
	type_specifier ID '(' ')'	                { sprintf($$, "%s %s function", $1, $2); create_symbol($$); }
    |
	type_specifier ID '(' parameter_list ')'	{ sprintf($$, "%s %s function parameter %s", $1, $2, $4); create_symbol($$); }
    ;

function_definition:
	type_specifier ID '(' ')'	                {
        if(!lookup_symbol($2, 0)){
            sprintf($$, "%s %s function", $1, $2);
            create_symbol($$);
        }
    }
    |
	type_specifier ID '(' parameter_list ')'	{
        if(!lookup_symbol($2, 0)){
        sprintf($$, "%s %s function parameter %s", $1, $2, $4);
            create_symbol($$);
        }
        create_symbol($4);
    }
    ;

type_specifier:
	VOID   { $$ = $1; }
	|
	INT    { $$ = $1; }
	|
	FLOAT  { $$ = $1; }
	|
	STRING { $$ = $1; }
	|
	BOOL   { $$ = $1; }
	;

parameter_list:
    parameter_declarator					{ $$ = $1; }
	|
	parameter_list ',' parameter_declarator	{ sprintf($$, "%s %s", $1, $3); }
	;

parameter_declarator:
    type_specifier ID   { sprintf($$, "%s %s", $1, $2); }
    ;

compound_statement:
	'{' '}'				    	{  }
	|
    '{'  block_item_list '}'	{  }
	;

block_item_list:
	block_item					{  }
	|
    block_item_list block_item	{  }
	;

block_item:
	variable_declaration	{
        create_symbol($1);
    }
	|
    statement              	{  }
	;

assignment_expression:
	unary_expression assignment_operator assignment_expression	{  }
	|
	conditional_expression										{  }
	;

unary_expression:
	postfix_expression				{  }
	|
	INC_OP unary_expression			{  }
	|
	DEC_OP unary_expression			{  }
	|
	unary_operator unary_expression	{  }
	;

postfix_expression:
	primary_expression {  }
	|
	ID '(' ')' {
        if(!lookup_symbol($1, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
        }
    }
	|
	ID '(' argument_expression_list ')'	{
        if(!lookup_symbol($1, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared function %s", $1);
        }
    }
	|
	postfix_expression INC_OP {  }
	|
	postfix_expression DEC_OP {  }
	;

primary_expression:
	ID					{
        if(!lookup_symbol($1, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $1);
        }
    }
	|
	constant			{  }
	|
	'(' expression ')'	{  }
	;

constant:
	I_CONST			{  }
	|
	F_CONST			{  }
	|
	TRUE			{  }
	|
	FALSE			{  }
	|
	STRING_LITERAL	{  }
	;

expression:
	assignment_expression					{  }
	|
    expression ',' assignment_expression	{  }
	;

argument_expression_list:
	assignment_expression								{  }
	|
    argument_expression_list ',' assignment_expression	{  }
	;

unary_operator:
	'+'	{  }
	|
    '-'	{  }
	|
    '!'	{  }
	;

assignment_operator:
	'='			{  }
	|
    MUL_ASSIGN	{  }
	|
    DIV_ASSIGN	{  }
	|
    MOD_ASSIGN	{  }
	|
    ADD_ASSIGN	{  }
	|
    SUB_ASSIGN	{  }
	;

conditional_expression:
	logical_or_expression											{  }
	|
    logical_or_expression '?' expression ':' conditional_expression	{  }
	;

logical_or_expression:
	logical_and_expression								{  }
	|
    logical_or_expression OR_OP logical_and_expression	{  }
	;

logical_and_expression:
	equality_expression								    {  }
	|
    logical_and_expression AND_OP equality_expression	{  }
	;

equality_expression:
	relational_expression							{  }
	|
    equality_expression EQ_OP relational_expression	{  }
	|
    equality_expression NE_OP relational_expression	{  }
	;

relational_expression:
	additive_expression								{  }
	|
    relational_expression '<' additive_expression	{  }
	|
    relational_expression '>' additive_expression	{  }
	|
    relational_expression LE_OP additive_expression	{  }
	|
    relational_expression GE_OP additive_expression	{  }
	;

additive_expression:
	multiplicative_expression							{  }
	|
    additive_expression '+' multiplicative_expression	{  }
	|
    additive_expression '-' multiplicative_expression	{  }
	;

multiplicative_expression:
	unary_expression								{  }
	|
    multiplicative_expression '*' unary_expression 	{  }
	|
    multiplicative_expression '/' unary_expression	{  }
	|
    multiplicative_expression '%' unary_expression	{  }
	;

statement:
	compound_statement	    {  }
	|
    expression_statement    {  }
	|
    selection_statement	    {  }
	|
    iteration_statement 	{  }
	|
    jump_statement		    {  }
	|
    print_statement	    	{  }
	;

expression_statement:
	';'				{  }
	|
    expression ';'	{  }
	;

selection_statement:
	IF '(' expression ')' statement %prec LOWER_THAN_ELSE	{  }
	|
    IF '(' expression ')' statement ELSE statement		{  }
	;

iteration_statement:
	WHILE '(' expression ')' statement											{  }
	|
    FOR '(' expression_statement expression_statement ')' statement				{  }
	|
    FOR '(' expression_statement expression_statement expression ')' statement	{  }
	|
    FOR '(' variable_declaration expression_statement ')' statement						{  }
	|
    FOR '(' variable_declaration expression_statement expression ')' statement			{  }
	;

jump_statement:
	RETURN ';'			    {  }
	|
    RETURN expression ';'	{  }
	;

print_statement:
	PRINT '(' ID ')' ';'				{
        if(!lookup_symbol($3, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Undeclared variable %s", $3);
        }

    }
	|
    PRINT '(' STRING_LITERAL ')' ';'	{  }
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    yyparse();

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

void create_symbol(char *signature){
	char name[64];
	char entryType[20];
	char dataType[10];
	int scope = 0;
	char parameter[128] = "";

    if(strstr(signature, "variable") != NULL){
        sscanf(signature, "%s %s %s %d", dataType, name, entryType, &scope);
        if(lookup_symbol(name, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared variable %s", name);
            return;
        }
    	symbol *tmp = malloc(sizeof(symbol));
        tmp->name = strdup(name);
        tmp->entryType = strdup(entryType);
        tmp->dataType = strdup(dataType);
        tmp->scope = scope;
        tmp->parameter = strdup("");
        insert_symbol(tmp);
    }
    else if(strstr(signature, "function") != NULL){
        sscanf(signature, "%s %s %s", dataType, name, entryType);
        if(lookup_symbol(name, currentScope)){
            errorFlag = 1;
            sprintf(errorMsg, "Redeclared variable %s", name);
            return;
        }
    	symbol *tmp = malloc(sizeof(symbol));
        tmp->name = strdup(name);
        tmp->entryType = strdup(entryType);
        tmp->dataType = strdup(dataType);
        tmp->scope = 0;
        if(strstr(signature, "parameter") != NULL){
            char *token = strtok(strstr(signature, "parameter"), " ");
            strcat(parameter, strtok(NULL, " "));
            strtok(NULL, " ");
            token = strtok(NULL, " ");
            while(token != NULL){
                strcat(parameter, ", ");
                strcat(parameter, token);
                strtok(NULL, " ");
                token = strtok(NULL, " ");
            }
            tmp->parameter = strdup(parameter);
        }
        else{
            tmp->parameter = strdup("");
        }
        insert_symbol(tmp);
    }
    else{
        char *token = strtok(signature, " ");
        while(token != NULL){
            symbol *paraTmp = malloc(sizeof(symbol));
            paraTmp->dataType = strdup(token);
            paraTmp->name = strdup(strtok(NULL, " "));
            paraTmp->entryType = strdup("parameter");
            paraTmp->scope = 1;
            paraTmp->parameter = strdup("");
            insert_symbol(paraTmp);
            token = strtok(NULL, " ");
        }
    }
}

void insert_symbol(symbol *s){
    table[s->scope][symbolCount[s->scope]++] = s;
}

int lookup_symbol(char *name, int scope){
    for(int j = scope; j >= 0; --j){
        for(int i = 0; i < symbolCount[j]; ++i){
            if(!strcmp(table[j][i]->name, name))
                return 1;
        }
    }
    return 0;
}

void dump_symbol(int scope) {
    if(symbolCount[scope] > 0){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n", "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        for(int i = 0; i < symbolCount[scope]; ++i){
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", i, table[scope][i]->name, table[scope][i]->entryType, table[scope][i]->dataType, table[scope][i]->scope, table[scope][i]->parameter);
        }
        printf("\n");
        for(int i = 0; i < symbolCount[scope]; ++i){
            free(table[scope][i]);
            table[scope][i] = NULL;
        }
        symbolCount[scope] = 0;
    }
}
