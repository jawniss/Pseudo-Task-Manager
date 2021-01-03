#include "other.h"
int main() {
    MyFunc();

    return 0;
}

/*
CFLAGS = -Wall -std=c++11

all: main other 
main: main
other: other

main: main.o other.o
	g++ -o test66 main.o other.o

main.o: main.cpp
	g++ -c main.cpp

other.o: other.cpp other.h
	g++ -c other.cpp

clean:
	@rm -rf other main *.o *.exe
*/

/*
main: main.cpp other.cpp
	g++ -o test1 main.cpp other.cpp -I.

clean:
	-del *.o *.exe
*/