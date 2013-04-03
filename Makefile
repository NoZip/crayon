
crayon: crayon.tab.o crayon.flex.o point.o path.o command.o
	g++ -o $@ $^ -lfl -lm

crayon.yy.cpp: crayon.lex crayon.tab.hpp
	flex -o $@ $<

crayon.tab.cpp: crayon.ypp
	bison -v -d $<

%.o: %.cpp %.h
	g++ -c -o $@ $<

clean:
	rm -f *.o *.yy.cpp *.tab.cpp *.tab.hpp *.output