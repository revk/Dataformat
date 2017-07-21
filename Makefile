dataformat.o: dataformat.c
	cc -Wall -Wextra -O -c -o dataformat.o dataformat.c -DLIB

clean:
	rm -f *.o
