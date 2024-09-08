%option noyywrap

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" printf("keyword: %s\n", yytext);
[0-9]+ printf("constant: %s\n", yytext);
[a-zA-Z_][a-zA-Z0-9_]* printf("identifier: %s\n", yytext);
%%

int main()
{
    yylex();
    return 0;
}