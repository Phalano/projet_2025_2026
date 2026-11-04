bin/menu: obj/menu.o
	gcc obj/menu.o -o bin/menu

obj/menu.o: src/menu.c 
	gcc -c src/menu.c -o obj/menu.o