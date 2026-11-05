all: main.o serpent.o 
	gcc main.o serpent.o -o serpent
main.o:
	gcc -c main.c -Wall
serpent.o:
	gcc -c serpent.c -Wall
clean:
	rm *.o ; rm serpent