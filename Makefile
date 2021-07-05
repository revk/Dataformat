all: dataformat.o dataformat

dataformat.o: dataformat.c
	cc -g -Wall -Wextra -O -c -o dataformat.o dataformat.c

dataformat: dataformat.c
	cc -g -Wall -Wextra -c -o dataformat.o dataformat.c

clean:
	rm -f *.o
