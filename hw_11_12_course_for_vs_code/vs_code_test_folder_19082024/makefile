all: prog

prog: main.o temp_function.o
	gcc -g -o prog main.o temp_function.o

main.o: main.c
	gcc -g -c -o main.o main.c

temp_function.o: temp_function.c
	gcc -g -c -o temp_function.o temp_function.c

clean:
	del *.o
	del prog.exe	