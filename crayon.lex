%{
#include <cstring>

#include "point.hpp"
#include "path.hpp"

#include "expression.hpp"
#include "inequation.hpp"
#include "instruction.hpp"
#include "command.hpp"

#include "flow.hpp"

#include "crayon.tab.hpp"

#define YY_DECL int yylex(YYSTYPE * yylval_param, YYLTYPE * yylloc_param)

extern "C" {
    int yylex(YYSTYPE * yylval_param,YYLTYPE * yylloc_param);
}

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
%}

%option yylineno

%%

[0-9]+(\.[0-9]+)?|\.[0-9]+ {
	yylval.real = atof(yytext);
	return REAL;
}

\; return SEMICOLON;

= return EQ;

\( return RPAR;
\) return LPAR;

\+ return PLUS;
- return MINUS;
\* return MUL;
\/ return DIV;


== return EQUAL;
!= return NEQUAL;
\> return GT;
\>= return GTE;
\< return LT;
\<= return LTE;
&& return AND;
\|\| return OR;
! return NOT;

, return COMMA;
: return DOUBLE_DOT;

-- return PATH_SEPARATOR;
cycle return CYCLE;

draw return DRAW_COMMAND;
fill return FILL_COMMAND;

translate return TRANSLATE_BUILDIN;
rotate return ROTATE_BUILDIN;

[_a-zA-Z][_a-zA-Z0-9]+ {
    yylval.name = strdup(yytext);
    return NAME;
}

\n yycolumn = 1;

. ;
