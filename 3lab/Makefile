all: main

main: main.o command.o coder.o
	gcc -Wall -o src/main main.o command.o coder.o
	rm -rf *.o

main.o: src/main.c
	gcc -Wall -o main.o -c src/main.c

command.o: src/command.c
	gcc -Wall -o command.o -c src/command.c

coder.o: src/coder.c
	gcc -Wall -o coder.o -c src/coder.c