inventory:inventory.o readline.o
	gcc -o inventory inventory.c

inventory.o:inventory.c readline.h
	gcc -c inventory.c

readline.o:readline.c readline.h
	gcc -c readline.c