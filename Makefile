all: sorted-list main libsl.a

sorted-list: sorted-list.o
	gcc -Wall -Werror -g sl -o sorted-list.o

sorted-list.o: sorted-list.c sorted-list.h
	gcc -Wall -Werror -g -c sorted-list.c

main: main.o
	gcc -Wall -Werror -g main -o main.o

main.o: main.c
	gcc -Wall -Werror -g -c main.c

libsla.a:
	ar r libsl.a sorted-list.o main.o

clean:
	rm -rf *.o