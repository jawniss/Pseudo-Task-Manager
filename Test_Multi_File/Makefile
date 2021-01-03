CFLAGS = -Wall -std=c++11

all: main other 
main: main
other: other

main: main.o other.o
	g++ main.o other.o -o test66

main.o: main.cpp
	g++ -c main.cpp -o main.o

other.o: other.cpp other.h
	g++ -c other.cpp -o other.o

clean:
	-del other main *.o *.exe