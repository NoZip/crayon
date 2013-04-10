%{
#include <string>

#include "point.hpp"
#include "path.hpp"
#include "command.hpp"

#include "crayon.tab.hpp"
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

[_a-zA-Z][_a-zA-Z0-9]+ {
    yylval.string = yytext;
    return NAME;
}

\n return NEWLINE;

. ;
