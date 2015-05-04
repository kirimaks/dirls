CFLAGS=-Wall -Wextra -pedantic -g
OUT=dirls
all:
	cc ${CFLAGS} main.c -o ${OUT} 

clean:
	rm ${OUT}
