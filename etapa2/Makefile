CC=gcc
LC=lex
BC=bison

etapa2: parser scanner c
	${CC} -o parser lex.yy.o parser.tab.o main.o

c: main.c parser.tab.c lex.yy.c
	${CC} -c main.c parser.tab.c lex.yy.c

scanner: scanner.l
	${LC} scanner.l

parser: parser.y
	${BC} -d parser.y

clean:
	rm *.o *.h lex.yy.c parser.tab.c

