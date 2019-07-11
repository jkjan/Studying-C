tetris: main.o tetrisfunc.o
	gcc -o tetris main.o tetrisfunc.o

main.o : main.c
	gcc -c main.c
tetrisfunc.o : tetrisfunc.c
	gcc -c tetrisfunc.c

all : hello
clean:
	rm -f *.o tetris
