gamepac: tetris.o keyboard.o tree.o mukchibba.o gamepac.o baseball.o
	gcc -o gamepac tetris.o keyboard.o tree.o mukchibba.o gamepac.o baseball.o -lpthread -lncurses -lm

tetris.o : tetris.c
	gcc -c tetris.c -lpthread -lncurses -lm
keyboard.o : keyboard.c
	gcc -c keyboard.c -lpthread -lncurses
tree.o : tree.c
	gcc -c tree.c -lncurses
mukchibba.o : mukchibba.c
	gcc -c mukchibba.c
gamepac.o : gamepac.c
	gcc -c gamepac.c -lncurses
baseball.o : baseball.c
	gcc -c baseball.c



all : gamepac
clean:
	rm -f *.o gamepac
