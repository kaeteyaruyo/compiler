%{
	#include <stdio.h>
	#include <stdlib.h>
    int lineCount = 0;
    int commentCount = 0;
%}

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
Int {digit}+
Float {digit}+.{digit}+
ws [ \t]+
CPPComment \/\/(.)*
%x comment
%x str_const

%%

"+"             { printf("%s \t ADD\n", yytext); }
"-"             { printf("%s \t SUB\n", yytext); }
"*"             { printf("%s \t MUL\n", yytext); }
"/"             { printf("%s \t DIV\n", yytext); }
"%"             { printf("%s \t MOD\n", yytext); }
"++"            { printf("%s \t INC\n", yytext); }
"--"            { printf("%s \t DEC\n", yytext); }
">"             { printf("%s \t MT\n", yytext); }
"<"             { printf("%s \t LT\n", yytext); }
">="            { printf("%s \t MTE\n", yytext); }
"<="            { printf("%s \t LTE\n", yytext); }
"=="            { printf("%s \t EQ\n", yytext); }
"!="            { printf("%s \t NE\n", yytext); }
"="             { printf("%s \t ASGN\n", yytext); }
"+="            { printf("%s \t ADDASGN\n", yytext); }
"-="            { printf("%s \t SUBASGN\n", yytext); }
"*="            { printf("%s \t MULASGN\n", yytext); }
"/="            { printf("%s \t DIVASGN\n", yytext); }
"%="            { printf("%s \t MODASGN\n", yytext); }
"&&"            { printf("%s \t AND\n", yytext); }
"||"            { printf("%s \t OR\n", yytext); }
"!"             { printf("%s \t NOT\n", yytext); }
"("             { printf("%s \t LB\n", yytext); }
")"             { printf("%s \t RB\n", yytext); }
"["             { printf("%s \t LSB\n", yytext); }
"]"             { printf("%s \t RSB\n", yytext); }
"{"             { printf("%s \t LCB\n", yytext); }
"}"             { printf("%s \t RCB\n", yytext); }
","             { printf("%s \t COMMA\n", yytext); }
";"             { printf("%s \t SEMICOLON\n", yytext); }
"print"         { printf("%s \t PRINT\n", yytext); }
"if"            { printf("%s \t IF\n", yytext); }
"else"          { printf("%s \t ELSE\n", yytext); }
"for"           { printf("%s \t FOR\n", yytext); }
"while"         { printf("%s \t WHILE\n", yytext); }
"string"        { printf("%s \t STRING\n", yytext); }
"int"           { printf("%s \t INT\n", yytext); }
"float"         { printf("%s \t FLOAT\n", yytext); }
"void"          { printf("%s \t VOID\n", yytext); }
"bool"          { printf("%s \t BOOL\n", yytext); }
"true"          { printf("%s \t TRUE\n", yytext); }
"false"         { printf("%s \t FALSE\n", yytext); }
"return"        { printf("%s \t RET\n", yytext); }
"continue"      { printf("%s \t CONT\n", yytext); }
"break"         { printf("%s \t BREAK\n", yytext); }
{id}            { printf("%s \t ID\n", yytext); }
{Int}           { printf("%s \t I_CONST\n", yytext); }
{Float}         { printf("%s \t F_CONST\n", yytext); }
"\""                    {
    printf("%s \t QUOTA\n", yytext);
    BEGIN(str_const);
}
<str_const>[^\"]*       { printf("%s", yytext); }
<str_const>"\""         {
    printf(" \t STR_CONST\n");
    printf("%s \t QUOTA\n", yytext);
    BEGIN(INITIAL);
}
"/*"                    {
    printf("%s", yytext);
    BEGIN(comment);
}
<comment>[^*\n]*        { printf("%s", yytext); }
<comment>"*"+[^*/\n]*   { printf("%s", yytext); }
<comment>\n             {
    printf("%s", yytext);
    ++lineCount;
    ++commentCount;
}
<comment>"*"+"/"        {
    commentCount++;
    printf("%s \t C Comment\n", yytext);
    BEGIN(INITIAL);
}
{CPPComment}    {
    commentCount++;
    printf("%s \t C++ Comment\n", yytext);
}
\n              { lineCount++; }
{ws}            { ; }

%%

int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
// CComment \/\*(\\.|[^"\\])*\*\/
// {CComment}      {
//     char* s = yytext;
//     int i;
//     for (i = 0; s[i]; s[i] == '\n' ? i++ : *s++);
//     commentCount += (i + 1);
//     lineCount += i;
//     printf("%s \t C COMMENT\n", yytext);
// }

	yyin = fopen(argv[1], "r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n", lineCount);
	printf("comment: %d lines\n\n", commentCount);

	return 0;
}
