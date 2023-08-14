etapa4: lex.yy.o parser.tab.o main.o ast.o
	gcc -g -o etapa4 lex.yy.o parser.tab.o main.o ast.o utils.o table.o

lex.yy.o parser.tab.o main.o ast.o: lex.yy.c parser.tab.c ast.c main.c
	gcc -g -c lex.yy.c main.c ast.c parser.tab.c utils.c table.c

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y --report-file=FILE

clean:
	rm -rf lex.yy.* parser.tab.* main.o ast.o etapa4

entrega:
	tar cvzf etapa4.tgz ast.c ast.h main.c Makefile parser.y scanner.l table.c table.h

qual:
	which gcc