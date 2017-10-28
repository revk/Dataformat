dataformat.o: dataformat.c
	cc -g -Wall -Wextra -O -c -o dataformat.o dataformat.c

clean:
	rm -f *.o
