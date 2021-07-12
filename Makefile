all: dataformat.o dataformat

dataformat.o: dataformat.c Makefile
	cc -g -Wall -Wextra -O -c -o dataformat.o dataformat.c -DLIB

dataformat: dataformat.c Makefile
	cc -g -Wall -Wextra -o dataformat dataformat.c

clean:
	rm -f *.o
