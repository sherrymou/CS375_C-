#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Sudoku{
	public:
	int matrix[9][9];
	string datafile;
	int nx = 0, ny = 0;
	int c = 1, num = 0;
	int ans[81][3];
	
	//Methods
	Sudoku();
	Sudoku(string datain);
	void bruteForce(string fileanme);
	void backtracking(string filename);
	void stochastic(string filename);
	
	private:
	bool isPromising(int matrixSol[9][9],int x, int y, int value);
	int* getSubMatrix(int solution[9][9],int x, int y);
	void output(int matrixSol[9][9], string filename);
	bool isValid(int matrixSol[9][9]);
	vector<int> getRest();
};

int main(int argc, const char *argv[]);
