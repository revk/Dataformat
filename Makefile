dataformat.o: dataformat.c
	cc -Wall -Wextra -O -c -o dataformat.o dataformat.c

clean:
	rm -f *.o
