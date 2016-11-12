all: Sequences Program1 Program2 Program3 

Sequences: Sequences.cpp
	g++ -std=c++0x -c Sequences.cpp

Program1: Program1.o 
	g++ -std=c++0x Sequences.o Program1.o -o program1

Program1.o: Program1.cpp
	g++ -std=c++0x -c Program1.cpp

Program2: Program2.o
	g++ -std=c++0x Program2.o Sequences.o -o program2

Program2.o: Program2.cpp
	g++ -std=c++0x -c Program2.cpp

Program3: Program3.o
	g++ -std=c++0x Program3.o Sequences.o -o program3

Program3.o: Program3.cpp
	g++ -std=c++0x -c Program3.cpp

clean:
	rm -f *.o program1 program2 program3
