all: isort txtfind

isort: main_isort.o isort.o
	gcc -o main_isort main_isort.o isort.o -Wall

isort.o: isort.c
	gcc -c isort.c -Wall

main_isort.o: main_isort.c
	gcc -c main_isort.c -Wall

txtfind: main_txtfind.o txtfind.o
	gcc -o main_txtfind main_txtfind.o txtfind.o -Wall

txtfind.o: txtfind.c
	gcc -c txtfind.c -Wall

main_txtfind.o: main_txtfind.c
	gcc -c main_txtfind.c -Wall

clean: 
	rm -f main_isort main_txtfind *.o
