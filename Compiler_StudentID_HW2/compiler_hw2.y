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

%type <string> declaration type_specifier init_declarator function_declarator function_definition parameter_list parameter_declarator

/* Yacc will start at this nonterminal */
%start translation_unit


%%

translation_unit:
	external_declaration					{ printf("external_declaration\n"); }
	|
	translation_unit external_declaration	{ printf("translation_unit external_declaration\n"); }
	;

external_declaration:
	declaration 			{ printf("!!!%s!!!\n", $1); printf("declaration\n"); }
	|
	function_definition 	{ printf("!!!%s!!!\n", $1); printf("function_definition\n"); }
	;

declaration:
	type_specifier init_declarator ';' { $$ = $1; strcat($$, " "); strcat($$, $2); printf("type_specifier init_declarator ';'\n"); }
	;

type_specifier:
	VOID   { $$ = $1; printf("VOID\n"); }
	|
	INT    { $$ = $1; printf("INT\n"); }
	|
	FLOAT  { $$ = $1; printf("FLOAT\n"); }
	|
	STRING { $$ = $1; printf("STRING\n"); }
	|
	BOOL   { $$ = $1; printf("BOOL\n"); }
	;

init_declarator:
	ID 								{ sprintf($$, "%s variable %d", $1, currentScope); printf("ID\n"); }
	|
	ID '=' assignment_expression	{ sprintf($$, "%s variable %d", $1, currentScope); printf("ID '=' assignment_expression\n"); }
    |
    function_declarator             { $$ = $1; printf("function_declarator\n"); }
	;

function_declarator:
	ID '(' ')'					{ $$ = $1; strcat($$, " function"); printf("ID '(' ')'\n"); }
	|
	ID '(' identifier_list ')'	{ printf("ID '(' identifier_list ')'\n"); }
	|
	ID '(' parameter_list ')'	{ $$ = $1; strcat($$, " funciton paramete "); strcat($$, $3); printf("ID '(' parameter_list ')'\n"); }
	;

identifier_list:
	ID						{ printf("ID\n"); }
	|
	identifier_list ',' ID	{ printf("identifier_list ',' ID\n"); }
	;

parameter_list:
    parameter_declarator					{ $$ = $1; printf("parameter_declarator\n"); }
	|
	parameter_list ',' parameter_declarator	{ $$ = $3; strcat($$, " "); strcat($$, $1); printf("parameter_list ',' parameter_declarator\n"); }
	;

parameter_declarator:
    type_specifier ID   { $$ = $1;  strcat($$, " "); strcat($$, $2); printf("type_specifier ID\n");}
    ;

assignment_expression:
	unary_expression assignment_operator assignment_expression	{ printf("unary_expression assignment_operator assignment_expression\n"); }
	|
	conditional_expression										{ printf("conditional_expression\n"); }
	;

unary_expression:
	postfix_expression				{ printf("postfix_expression\n"); }
	|
	INC_OP unary_expression			{ printf("INC_OP unary_expression\n"); }
	|
	DEC_OP unary_expression			{ printf("DEC_OP unary_expression\n"); }
	|
	unary_operator unary_expression	{ printf("unary_operator unary_expression\n"); }
	;

postfix_expression:
	primary_expression									{ printf("primary_expression\n"); }
	|
	postfix_expression '(' ')'							{ printf("postfix_expression '(' ')'\n"); }
	|
	postfix_expression '(' argument_expression_list ')'	{ printf("postfix_expression '(' argument_expression_list ')'\n"); }
	|
	postfix_expression INC_OP							{ printf("postfix_expression INC_OP\n"); }
	|
	postfix_expression DEC_OP							{ printf("postfix_expression DEC_OP\n"); }
	;

primary_expression:
	ID					{ printf("ID\n"); }
	|
	constant			{ printf("constant\n"); }
	|
	'(' expression ')'	{ printf("'(' expression ')'\n"); }
	;

constant:
	I_CONST			{ printf("I_CONST\n"); }
	|
	F_CONST			{ printf("F_CONST\n"); }
	|
	TRUE			{ printf("TRUE\n"); }
	|
	FALSE			{ printf("FALSE\n"); }
	|
	STRING_LITERAL	{ printf("STRING_LITERAL\n"); }
	;

expression:
	assignment_expression					{ printf("assignment_expression\n"); }
	|
    expression ',' assignment_expression	{ printf("expression ',' assignment_expression\n"); }
	;

argument_expression_list:
	assignment_expression								{ printf("assignment_expression\n"); }
	|
    argument_expression_list ',' assignment_expression	{ printf("argument_expression_list ',' assignment_expression\n"); }
	;

unary_operator:
	'+'	{ printf("'+'\n"); }
	|
    '-'	{ printf("'-'\n"); }
	|
    '!'	{ printf("'!'\n"); }
	;

assignment_operator:
	'='			{ printf("'='\n"); }
	|
    MUL_ASSIGN	{ printf("MUL_ASSIGN\n"); }
	|
    DIV_ASSIGN	{ printf("DIV_ASSIGN\n"); }
	|
    MOD_ASSIGN	{ printf("MOD_ASSIGN\n"); }
	|
    ADD_ASSIGN	{ printf("ADD_ASSIGN\n"); }
	|
    SUB_ASSIGN	{ printf("SUB_ASSIGN\n"); }
	;

conditional_expression:
	logical_or_expression											{ printf("logical_or_expression\n"); }
	|
    logical_or_expression '?' expression ':' conditional_expression	{ printf("logical_or_expression '?' expression ':' conditional_expression\n"); }
	;

logical_or_expression:
	logical_and_expression								{ printf("logical_and_expression\n"); }
	|
    logical_or_expression OR_OP logical_and_expression	{ printf("logical_or_expression OR_OP logical_and_expression\n"); }
	;

logical_and_expression:
	equality_expression								    { printf("equality_expression\n"); }
	|
    logical_and_expression AND_OP equality_expression	{ printf("logical_and_expression AND_OP equality_expression\n"); }
	;

equality_expression:
	relational_expression							{ printf("relational_expression\n"); }
	|
    equality_expression EQ_OP relational_expression	{ printf("equality_expression EQ_OP relational_expression\n"); }
	|
    equality_expression NE_OP relational_expression	{ printf("equality_expression NE_OP relational_expression\n"); }
	;

relational_expression:
	additive_expression								{ printf("additive_expression\n"); }
	|
    relational_expression '<' additive_expression	{ printf("relational_expression '<' additive_expression\n"); }
	|
    relational_expression '>' additive_expression	{ printf("relational_expression '>' additive_expression\n"); }
	|
    relational_expression LE_OP additive_expression	{ printf("relational_expression LE_OP additive_expression\n"); }
	|
    relational_expression GE_OP additive_expression	{ printf("relational_expression GE_OP additive_expression\n"); }
	;

additive_expression:
	multiplicative_expression							{ printf("multiplicative_expression\n"); }
	|
    additive_expression '+' multiplicative_expression	{ printf("additive_expression '+' multiplicative_expression\n"); }
	|
    additive_expression '-' multiplicative_expression	{ printf("additive_expression '-' multiplicative_expression\n"); }
	;

multiplicative_expression:
	unary_expression								{ printf("unary_expression\n"); }
	|
    multiplicative_expression '*' unary_expression 	{ printf("multiplicative_expression '*' unary_expression\n"); }
	|
    multiplicative_expression '/' unary_expression	{ printf("multiplicative_expression '/' unary_expression\n"); }
	|
    multiplicative_expression '%' unary_expression	{ printf("multiplicative_expression '%' unary_expression\n"); }
	;

function_definition:
	type_specifier function_declarator compound_statement	{ $$ = $1; strcat($$, " "); strcat($$, $2); printf("type_specifier function_declarator compound_statement\n"); }
	;

compound_statement:
	'{' '}'				    	{ printf("'{' '}'\n"); }
	|
    '{'  block_item_list '}'	{ printf("'{'  block_item_list '}'\n"); }
	;

block_item_list:
	block_item					{ printf("block_item\n"); }
	|
    block_item_list block_item	{ printf("block_item_list block_item\n"); }
	;

block_item:
	declaration	{ printf("!!!%s!!!\n", $1); printf("declaration\n"); }
	|
    statement	{ printf("statement\n"); }
	;

statement:
	compound_statement	    { printf("compound_statement\n"); }
	|
    expression_statement    { printf("expression_statement\n"); }
	|
    selection_statement	    { printf("selection_statement\n"); }
	|
    iteration_statement 	{ printf("iteration_statement\n"); }
	|
    jump_statement		    { printf("jump_statement\n"); }
	|
    print_statement	    	{ printf("print_statement\n"); }
	;

expression_statement:
	';'				{ printf("';'\n"); }
	|
    expression ';'	{ printf("expression ';'\n"); }
	;

selection_statement:
	IF '(' expression ')' statement %prec LOWER_THAN_ELSE	{ printf("IF '(' expression ')' statement %prec LOWER_THAN_ELSE\n"); }
	|
    IF '(' expression ')' statement ELSE statement		{ printf("IF '(' expression ')' statement ELSE statement\n"); }
	;

iteration_statement:
	WHILE '(' expression ')' statement											{ printf("WHILE '(' expression ')' statement\n"); }
	|
    FOR '(' expression_statement expression_statement ')' statement				{ printf("FOR '(' expression_statement expression_statement ')' statement\n"); }
	|
    FOR '(' expression_statement expression_statement expression ')' statement	{ printf("FOR '(' expression_statement expression_statement expression ')' statement\n"); }
	|
    FOR '(' declaration expression_statement ')' statement						{ printf("FOR '(' declaration expression_statement ')' statement\n"); }
	|
    FOR '(' declaration expression_statement expression ')' statement			{ printf("FOR '(' declaration expression_statement expression ')' statement\n"); }
	;

jump_statement:
	RETURN ';'			    { printf("RETURN ';'\n"); }
	|
    RETURN expression ';'	{ printf("RETURN expression ';'\n"); }
	;

print_statement:
	PRINT '(' ID ')' ';'				{ printf("PRINT '(' ID ')' ';'\n"); }
	|
    PRINT '(' STRING_LITERAL ')' ';'	{ printf("PRINT '(' STRING_LITERAL ')' ';'\n"); }
	;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;

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
