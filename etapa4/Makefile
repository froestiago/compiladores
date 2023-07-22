etapa4: lex.yy.o parser.tab.o main.o ast.o table.o
	gcc -g -o etapa3 lex.yy.o parser.tab.o main.o ast.o table.o

lex.yy.o parser.tab.o main.o ast.o: lex.yy.c parser.tab.c ast.c table.c main.c
	gcc -g -c lex.yy.c main.c ast.c table.c parser.tab.c

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y --report-file=FILE

clean:
	rm -rf lex.yy.* parser.tab.* main.o ast.o etapa3

entrega:
	tar cvzf etapa3.tgz ast.c ast.h main.c Makefile parser.y scanner.l