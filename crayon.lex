%{
#include "crayon.bison.hpp"
%}

%%

[1-9]+(?:\.[0-9]+)?|\.[0-9]+ {
	yylval.real = atof(yytext);
	return REAL;
}

\( return RPAR;
\) return LPAR;

\+ return PLUS;
- return MINUS;
\* return MUL;
\/ return DIV;

, return COMMA;
: return DOUBLE_POINT;

-- return PATH_SEPARATOR;
cycle return CYCLE;

draw return DRAW_COMMAND;
fill return FILL_COMMAND;

\n return NEWLINE;

. ;
