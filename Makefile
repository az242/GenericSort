all: sorted-list.o main.o libsl.a create

create:
	gcc -o sl sorted-list.c main.c

sorted-list.o: sorted-list.c sorted-list.h
	gcc -Wall -Werror -c sorted-list.c

main.o: main.c
	gcc -Wall -Werror -c main.c

libsla.a:
	ar r libsl.a sorted-list.o main.o

clean:
	rm -rf *.o