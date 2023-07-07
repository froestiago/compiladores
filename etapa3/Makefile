CC=gcc
LC=lex
BC=bison
 
etapa3: lex.yy.o parser.tab.o ast.o
	${CC} -o etapa3 lex.yy.o ast.o parser.tab.o 

main.o: main.c lex.yy.c
	${CC} -c main.c

ast.o: ast.c
	${CC} -c ast.c

lex.yy.o: lex.yy.c
	${CC} -c lex.yy.c

lex.yy.c: scanner.l parser.tab.o
	${LC} --header-file=lex.yy.h scanner.l

parser.tab.o: parser.tab.c
	${CC} -c parser.tab.c

parser.tab.c: parser.y
	${BC} -d -v -t parser.y