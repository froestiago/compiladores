CC=gcc
LC=lex
BC=bison
 
etapa3: lex.yy.o parser.tab.o ast.o valor_lexico.o
	${CC} -o etapa3 lex.yy.o ast.o valor_lexico.o parser.tab.o 

main.o: main.c lex.yy.c
	${CC} -c main.c

valor_lexico.o: valor_lexico.c
	$(CC) -c valor_lexico.c

ast.o: ast.c
	${CC} -c ast.c

lex.yy.o: lex.yy.c
	${CC} -c lex.yy.c

lex.yy.c: scanner.l parser.tab.o
	${LC} --header-file=lex.yy.h scanner.l

parser.tab.o: parser.tab.c
	${CC} -c parser.tab.c

parser.tab.c: parser.y
	${BC} -d parser.y

clean:
	rm -rf etapa3 lex* *.o parser.tab*