
/* calculator */

%{

#include "calc.tab.h"

int yylval;
char *ep;
%}

%%

"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
"|"	{ return ABS; }
[0-9]+	{ yylval = atoi(yytext); return NUMBER; } /* decimal number */
\n	{ return EOL; }
[ \t]	{ /* ignore whitespace */ }
"("	{ return OP; }
")"	{ return CP; }
"//".*	{ return COMMENT; } /* ignore comments */
.	{ printf("Mystery character %c\n", *yytext); }

%%

/*int main(int argc, char **argv)
{

	yylex();

	return 0;
}*/
