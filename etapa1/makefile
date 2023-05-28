etapa1: lex.yy.o main.o
	gcc lex.yy.o main.o -o etapa1
main.o: main.c
	gcc -c main.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
lex.yy.c: scanner.l
	flex scanner.l
clean:
	rm *.o lex.yy.c etapa1
