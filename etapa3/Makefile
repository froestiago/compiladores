CC=gcc
LC=lex
BC=bison

etapa3: scanner parser c
	${CC} -o etapa3 lex.yy.o parser.tab.o main.o

c: main.c parser.tab.c lex.yy.c
	${CC} -c main.c parser.tab.c lex.yy.c

scanner: scanner.l
	${LC} scanner.l

parser: parser.y
	${BC} -d parser.y

clean:
	rm -rf etapa3 lex* *.o parser.tab*