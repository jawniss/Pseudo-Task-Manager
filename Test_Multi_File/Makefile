CFLAGS = -Wall -std=c++11

# Linker:
main: main.o other.o
	g++ main.o other.o $(CFLAGS) -o test66

# Compilation commands:
main.o: main.cpp
	g++ -c main.cpp $(CFLAGS) -o main.o

other.o: other.cpp other.h
	g++ -c other.cpp $(CFLAGS) -o other.o

clean:
	-del other main *.o *.exe