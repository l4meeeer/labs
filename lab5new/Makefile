#Makefile for sinterp project

str: strings.o main.o
	gcc -o str strings.o main.o

strings.o: strings.c
	gcc -c strings.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o str
