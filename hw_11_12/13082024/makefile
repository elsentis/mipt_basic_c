all: prog

prog: main.o temp_function.o
	gcc -o prog main.o temp_function.o

main.o: main.c
	gcc -c -o main.o main.c

temp_function.o: temp_function.c
	gcc -c -o temp_function.o temp_function.c

clean:
	del *.o
	del prog.exe	