CFLAGS = -Wall -std=c++11

all: main
main_Cookie_Clicker: main_Cookie_Clicker.o 
Find_Windows: Find_Windows.o 

# Linker:
main: main_Cookie_Clicker.o Find_Windows.o globals.o Focus_Window.o
	g++ main_Cookie_Clicker.o Find_Windows.o globals.o Focus_Window.o $(CFLAGS) -o test

# Compilation commands:
main_Cookie_Clicker.o: main_Cookie_Clicker.cpp
	g++ -c main_Cookie_Clicker.cpp $(CFLAGS) -o main_Cookie_Clicker.o

Find_Windows.o: Find_Windows.cpp Find_Windows.h
	g++ -c Find_Windows.cpp $(CFLAGS) -o Find_Windows.o

globals.o: globals.cpp globals.h
	g++ -c globals.cpp $(CFLAGS) -o globals.o

Focus_Window.o: Focus_Window.cpp Focus_Window.h
	g++ -c Focus_Window.cpp $(CFLAGS) -o Focus_Window.o

clean:
	-del Find_Windows main_Cookie_Clicker *.o *.exe