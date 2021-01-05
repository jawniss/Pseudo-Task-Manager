CFLAGS = -Wall -std=c++11

all: main
Focus_Window: Focus_Window.o 
Find_Windows: Find_Windows.o 
globals: globals.o
User_Interface: User_Interface.o

# Linker:
main: main.o Find_Windows.o globals.o Focus_Window.o User_Interface.o
	g++ main.o Find_Windows.o globals.o Focus_Window.o User_Interface.o $(CFLAGS) -o test

# Compilation commands:
main.o: main.cpp
	g++ -c main.cpp $(CFLAGS) -o main.o

Find_Windows.o: Find_Windows.cpp Find_Windows.h
	g++ -c Find_Windows.cpp $(CFLAGS) -o Find_Windows.o

globals.o: globals.cpp globals.h
	g++ -c globals.cpp $(CFLAGS) -o globals.o

Focus_Window.o: Focus_Window.cpp Focus_Window.h
	g++ -c Focus_Window.cpp $(CFLAGS) -o Focus_Window.o

User_Interface.o: User_Interface.cpp User_Interface.h
	g++ -c User_Interface.cpp $(CFLAGS) -o User_Interface.o

clean:
	-del Find_Windows main *.o *.exe