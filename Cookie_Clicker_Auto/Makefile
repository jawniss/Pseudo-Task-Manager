CFLAGS = -Wall -std=c++11

all: main
main_Cookie_Clicker: main_Cookie_Clicker.o 
Find_Windows: Find_Windows.o 

# Linker:
main: main_Cookie_Clicker.o Find_Windows.o
	g++ main_Cookie_Clicker.o Find_Windows.o $(CFLAGS) -o test

# Compilation commands:
main_Cookie_Clicker.o: main_Cookie_Clicker.cpp
	g++ -c main_Cookie_Clicker.cpp $(CFLAGS) -o main_Cookie_Clicker.o

Find_Windows.o: Find_Windows.cpp Find_Windows.h
	g++ -c Find_Windows.cpp $(CFLAGS) -o Find_Windows.o

clean:
	-del Find_Windows main_Cookie_Clicker *.o *.exe