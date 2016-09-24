CC = g++
FLAGS =-g -ftest-coverage -fprofile-arcs

TesteRomano: roman.c teste.c
	$(CC) $(FLAGS) teste.c roman.c -o TesteRoman -lgtest
clean:
	rm -rf *o gteste