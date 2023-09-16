etapa5: lex.yy.o parser.tab.o main.o ast.o
	gcc -g -o etapa5 lex.yy.o parser.tab.o main.o ast.o utils.o table.o code.o

lex.yy.o parser.tab.o main.o ast.o table.o code.o: lex.yy.c parser.tab.c ast.c main.c table.c code.c
	gcc -g -c lex.yy.c main.c ast.c parser.tab.c utils.c table.c code.c

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y --report-file=FILE

clean:
	rm -rf lex.yy.* parser.tab.* main.o ast.o table.o code.o utils.o etapa5

entrega:
	tar cvzf etapa5.tgz ast.c ast.h main.c Makefile parser.y scanner.l table.c table.h code.c code.h utils.c utils.h

which:
	which gcc