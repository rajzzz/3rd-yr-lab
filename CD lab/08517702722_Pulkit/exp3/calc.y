%{
#include <stdio.h>
int regs[26];
int base;
%}
%start list
%token DIGIT LETTER
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'   /* operator precedence is low to high from top to bottom*/
%%                   /* beginning of rules section */
list:                       /*empty */
         |
        list stat '\n'
         |
        list error '\n'
         {
           printf("Syntax error\n");
           yyerrok;
         }
         ;
stat:    expr
         {
           printf("%d\n",$1);
         }
         |
         LETTER '=' expr
         {
           printf("value assigned successfully\n");
           regs[$1] = $3;
         }
         ;
expr:    '(' expr ')'
         {
           $$ = $2;
         }
         |
         expr '+' expr
         {
           $$ = $1 + $3;
         }
          |
         expr '-' expr
         {
           $$ = $1 - $3;
         }
         |
         expr '*' expr
         {
           $$ = $1 * $3;
         }
         |
         expr '/' expr
         {
           $$ = $1 / $3;
         }
         |
         expr '%' expr
         {
           $$ = $1 % $3;
         }
         |
         LETTER
         {
           $$ = regs[$1];
         }
         |
         number
         ;
number:  DIGIT
         {
           //printf("first here!!");
           $$ = $1;
           base = ($1==0) ? 8 : 10;
         }       |
         number DIGIT
         {
           printf("%d %d \n", $1, $2);
           $$ = base * $1 + $2;
         }
         ;
%%
main()
{
 return(yyparse());
}
yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
yywrap()
{
  return(1);
}
