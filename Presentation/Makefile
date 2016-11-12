all: Sudoku
	
Sudoku: sudoku.o
		g++ -std=c++0x sudoku.o -o Sudoku

sudoku.o: sudoku.cpp
		g++ -std=c++0x -c sudoku.cpp

clean:
		rm -f *.o Sudoku
