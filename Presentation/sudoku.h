#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Sudoku{
	public:
	int matrix[9][9];
	string datafile;
	
	private:
	int nx = 0, ny = 0;
	int num = 0;
	int pos = 0;
	int ans[81][3];
	int btSol[9][9];
	
	//Methods
	public:
	Sudoku();
	Sudoku(string datain);
	void bruteForce(string fileanme);
//	void backtracking(int presolution[9][9], int x, int y, int n, string filename);
	void backtracking(string filename);
	void stochastic(string filename);
	
	private:
	void _backtracking(int n);
	bool isPromising(int matrixSol[9][9],int x, int y, int value);
	int* getSubMatrix(int solution[9][9],int x, int y);
	void output(int matrixSol[9][9], string filename);
	bool isValid(int matrixSol[9][9]);
	vector<int> getRest();
};

int main(int argc, const char *argv[]);
