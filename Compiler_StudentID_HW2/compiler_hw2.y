/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *name;
	char *kind;
	char *type;
	int scope;
	char *attribute;
} symbol;

symbol *table[10][30];
int tableHead[10] = {0};
int currentScope = 0;
char symbolBuf[512];

extern int yylineno;
extern int yylex();
void yyerror(char *s);
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
symbol *create_symbol(char *name, char *kind, char *type, int scope, char *attribute);
void insert_symbol();
void dump_symbol();

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

%type <string> declaration type_specifier init_declarator declarator function_definition parameter_list

/* Yacc will start at this nonterminal */
%start translation_unit


%%

translation_unit:
	external_declaration					{  }
	|
	translation_unit external_declaration	{  }
	;

external_declaration:
	declaration 			{ printf("%s %d\n", $1, currentScope); }
	|
	function_definition 	{ printf("%s %d\n", $1, currentScope); }
	;

declaration:
	type_specifier init_declarator ';' { $$ = $1; strcat($$, " variable "); strcat($$, $2); }
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

init_declarator:
	declarator 								{ $$ = $1; }
	|
	declarator '=' assignment_expression	{ $$ = $1; }
	;

declarator:
	ID						   	{ $$ = $1; }
	|
	ID '(' ')'					{ $$ = $1; strcat($$, " function"); }
	|
	ID '(' identifier_list ')'	{  }
	|
	ID '(' parameter_list ')'	{ $$ = $1; strcat($$, " function"); strcat($$, " "); strcat($$, $3); }
	;

identifier_list:
	ID						{  }
	|
	identifier_list ',' ID	{  }
	;

parameter_list:
	type_specifier declarator						{ $$ = $1; strcat($2, " parameter"); printf("%s %s %d\n", $1, $2, currentScope); }
	|
	parameter_list ',' type_specifier declarator	{ $$ = $3; strcat($$, " "); strcat($$, $1); strcat($4, " parameter"); printf("%s %s %d\n", $3, $4, currentScope); }
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
	type_specifier declarator compound_statement	{ $$ = $1; strcat($$, " "); strcat($$, $2); }
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
	declaration	{ printf("%s %d\n", $1, currentScope); }
	|
    statement	{  }
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
    FOR '(' declaration expression_statement ')' statement						{  }
	|
    FOR '(' declaration expression_statement expression ')' statement			{  }
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
	printf("yytext: %s\n", yytext);
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

symbol *create_symbol(char *name, char *kind, char *type, int scope, char *attribute){
	symbol *tmp = malloc(sizeof(symbol));
	tmp->name = strdup(name);
	tmp->kind = strdup(kind);
	tmp->type = strdup(type);
	tmp->scope = scope;
	tmp->attribute = strdup(attribute);
	return tmp;
}

void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}
