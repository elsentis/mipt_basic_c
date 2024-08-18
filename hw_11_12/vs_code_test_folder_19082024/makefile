all: prog

prog: main.o
	gcc -g -o prog main.o

main.o: main.c
	gcc -g -c -o main.o main.c

clean:
	del *.o
	del prog.exe	