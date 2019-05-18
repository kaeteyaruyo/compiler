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

%type <string> variable_declaration function_declaration type_specifier function_declarator
%type <string> function_definition parameter_list parameter_declarator

/* Yacc will start at this nonterminal */
%start translation_unit


%%

translation_unit:
	external_declaration			    	{  }
	|
	translation_unit external_declaration	{  }
	;

external_declaration:
	variable_declaration	{ create_symbol($1); }
	|
	function_declaration 	{ create_symbol($1); }
	|
	function_definition 	{ create_symbol($1); }
	;

variable_declaration:
	type_specifier ID ';'                           { sprintf($$, "%s %s variable %d", $1, $2, currentScope); }
    |
	type_specifier ID '=' assignment_expression ';' { sprintf($$, "%s %s variable %d", $1, $2, currentScope); }
	;

function_declaration:
	type_specifier function_declarator ';' { sprintf($$, "%s %s", $1, $2); }
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

function_declarator:
	ID '(' ')'					{ sprintf($$, "%s function", $1); }
	|
	ID '(' identifier_list ')'	{  }
	|
	ID '(' parameter_list ')'	{ sprintf($$, "%s function parameter %s", $1, $3); }
	;

identifier_list:
	ID						{  }
	|
	identifier_list ',' ID	{  }
	;

parameter_list:
    parameter_declarator					{ $$ = $1; }
	|
	parameter_list ',' parameter_declarator	{ sprintf($$, "%s %s", $1, $3); }
	;

parameter_declarator:
    type_specifier ID   { sprintf($$, "%s %s", $1, $2); }
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
	primary_expression									{  }
	|
	postfix_expression '(' ')'							{  }
	|
	postfix_expression '(' argument_expression_list ')'	{  }
	|
	postfix_expression INC_OP							{  }
	|
	postfix_expression DEC_OP							{  }
	;

primary_expression:
	ID					{  }
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

function_definition:
	type_specifier function_declarator compound_statement	{ sprintf($$, "%s %s", $1, $2); }
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
	variable_declaration	{ create_symbol($1); }
	|
    statement              	{  }
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
	PRINT '(' ID ')' ';'				{  }
	|
    PRINT '(' STRING_LITERAL ')' ';'	{  }
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
	printf("\nTotal lines: %d \n", yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol(char *signature){
	char name[64];
	char entryType[20];
	char dataType[10];
	int scope = 0;
	char parameter[128] = "";

    if(strstr(signature, "variable") != NULL){
        sscanf(signature, "%s %s %s %d", dataType, name, entryType, &scope);
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
        if(lookup_symbol(name, 0)) return;
    	symbol *tmp = malloc(sizeof(symbol));
        tmp->name = strdup(name);
        tmp->entryType = strdup(entryType);
        tmp->dataType = strdup(dataType);
        tmp->scope = 0;
        if(strstr(signature, "parameter") != NULL){
            char *token = strtok(strstr(signature, "parameter"), " ");
            symbol *paraTmp = malloc(sizeof(symbol));
            paraTmp->dataType = strdup(strtok(NULL, " "));
            strcat(parameter, paraTmp->dataType);
            paraTmp->name = strdup(strtok(NULL, " "));
            paraTmp->entryType = strdup("parameter");
            paraTmp->parameter = strdup("");
            paraTmp->scope = 1;
            insert_symbol(paraTmp);
            token = strtok(NULL, " ");
            while(token != NULL){
                symbol *paraTmp = malloc(sizeof(symbol));
                paraTmp->dataType = strdup(token);
                strcat(parameter, ", ");
                strcat(parameter, paraTmp->dataType);
                paraTmp->name = strdup(strtok(NULL, " "));
                paraTmp->entryType = strdup("parameter");
                paraTmp->scope = 1;
                paraTmp->parameter = strdup("");
                insert_symbol(paraTmp);
                token = strtok(NULL, " ");
            }
            tmp->parameter = strdup(parameter);
        }
        else{
            tmp->parameter = strdup("");
        }
        insert_symbol(tmp);
    }
}

void insert_symbol(symbol *s){
    table[s->scope][symbolCount[s->scope]++] = s;
}

int lookup_symbol(char *name, int scope){
    for(int i = 0; i < symbolCount[scope]; ++i){
        if(!strcmp(table[scope][i]->name, name))
            return 1;
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
