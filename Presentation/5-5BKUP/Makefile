all: Sudoku
	
Sudoku: Sudoku.o
		g++ -std=c++0x Sudoku.o -o Sudoku

Sudoku.o: Sudoku.cpp
		 g++ -std=c++0x -c Sudoku.cpp

clean:
		rm -f *.o Sudoku