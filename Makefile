all: main.o user.o
	gcc -o struct_test main.o user.o

main.o: main.c user.h
	gcc -c main.c

user.o: user.c user.h
	gcc -c user.c

run:
	./struct_test

clean:
	rm *.o
