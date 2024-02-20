all: StrList

StrList: StrList.o Main.o
	gcc -Wall -g -o StrList StrList.o Main.o

StrList.o: StrList.c
	gcc -Wall -g -c StrList.c -o StrList.o

Main.o: Main.c
	gcc -Wall -g -c Main.c -o Main.o

clean:
	rm -f *.o StrList

.PHONY: all clean