
crayon : crayon.bison.o crayon.flex.o point.o path.o command.o
	g++ -o $@ $^ -lfl -lm

%.o : %.cpp %.h
	g++ -c -o $@ $<

crayon.flex.cpp : crayon.lex
	flex -o $@ $<

crayon.bison.cpp : crayon.ypp
	bison -o $@ $<