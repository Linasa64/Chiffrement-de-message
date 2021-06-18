GCC = gcc
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})


all: main

main: ${BINAIRES}
#${GCC} calculatrice.o main.c -o main
	${GCC} $^ -o $@
	
clean:
	rm main
	rm *.o
