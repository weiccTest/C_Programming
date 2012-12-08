inventory:inventory.o readline.o
	gcc -g -o inventory inventory.o readline.o

readline.o:readline.c readline.h
	gcc -g -c readline.c
	
inventory.o:inventory.c readline.h
	gcc -g -c inventory.c
