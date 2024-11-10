%{
#include <stdio.h>
%}

%option noyywrap

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"    { printf("Keyword: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*    { printf("Valid Identifier: %s\n", yytext); }

[0-9][a-zA-Z0-9_]*        { printf("Invalid Identifier: %s (cannot start with digit)\n", yytext); }
[@#$%^&*-+][a-zA-Z0-9_]*  { printf("Invalid Identifier: %s (cannot start with special character)\n", yytext); }

[ \t\n]+    ; /* Skip whitespace */

.    { printf("Invalid token: %s\n", yytext); }

%%

int main() {
    printf("Enter identifiers (Ctrl+D to end):\n");
    yylex();
    return 0;
}