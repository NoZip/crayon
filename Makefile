CC_FLAGS=-g

INCLUDES=-I/usr/include/cairo/

crayon: crayon.tab.o crayon.yy.o point.o error.o path.o command.o variable_affectation.o flow.o environment.o expression.o point_expression.o inequation.o for.o while.o conditional.o
	g++ ${CC_FLAGS} -std=c++11 -o $@ $^ -lm -lcairo -lfl

crayon.yy.cpp: crayon.lex crayon.tab.hpp
	flex -o $@ $<

crayon.tab.cpp: crayon.ypp
	bison -v -d $<

%.o: %.cpp
	g++ ${CC_FLAGS} -std=c++11 -c -o $@ ${INCLUDES} $<

clean:
	rm -f *.o *.yy.cpp *.tab.cpp *.tab.hpp *.output
