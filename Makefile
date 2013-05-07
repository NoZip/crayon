
INCLUDES=-I/usr/include/cairo/

crayon: crayon.tab.o crayon.yy.o point.o path.o command.o flow.o environment.o expression.o inequation.o conditional.o
	g++ -o $@ $^ -lcairo -ll -lfl -lm

crayon.yy.cpp: crayon.lex crayon.tab.hpp
	flex -o $@ $<

crayon.tab.cpp: crayon.ypp
	bison -v -d $<

%.o: %.cpp
	g++ -std=c++11 -c -o $@ ${INCLUDES} $<

clean:
	rm -f *.o *.yy.cpp *.tab.cpp *.tab.hpp *.output
