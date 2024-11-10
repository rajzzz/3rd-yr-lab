%option noyywrap

%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|restrict|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while    { printf("Keyword: %s\n", yytext); }

[0-9]+    { printf("Constant: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*    { printf("Valid Identifier: %s\n", yytext); }

[0-9][a-zA-Z0-9_]+        { printf("Invalid Identifier: %s (cannot start with digit)\n", yytext); }

[@#$%^&*\-+][a-zA-Z0-9_]*  { printf("Invalid Identifier: %s (cannot start with special character)\n", yytext); }

[ \t\n]+    ; 

.    { printf("Invalid token: %s\n", yytext); }

%%

int main() {
    printf("Enter input (Ctrl+D to end):\n");
    yylex();
    return 0;
}