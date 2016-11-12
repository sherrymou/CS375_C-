#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "sudoku.h"
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku(){}

Sudoku::Sudoku(string datain){

	datafile = datain;
	ifstream file(datafile);
	string temp, xstr, ystr, valuestr;
	int x,y,value;

	for (int i =0; i<9; i++){
		for (int j =0; j<9; j++){
			matrix[i][j]=0;
		}
	}
	
	while (getline(file,temp)){
		istringstream ss(temp);
		getline(ss,xstr, ' ');
		getline(ss,ystr, ' ');
		getline(ss, valuestr, ' ');
		
		x = stoi(xstr);
		y = stoi(ystr);
		value = stoi (valuestr);
		
		matrix[x][y] = value;
	}
	file.close();
	cout << "Leave constructor" << endl;
}

bool Sudoku::isPromising(int solution[9][9],int x, int y, int value){
	//Check Row
	for (int i = 0; i<9; i++){
		if (solution[x][i] == value) return false;
	}
	
	//Check Col
	for (int i = 0; i<9; i++){
		if (solution[i][y]== value) return false;
	}
	
	//Check the sub square
	int* sub = getSubMatrix(solution,x,y);
	for (int i=0; i<9; i++){
		if (sub[i]== value) return false;
	}
	
	return true;
}

int* Sudoku::getSubMatrix(int solution[9][9], int x, int y){
	int *sub = new int[9];
	int xs = x/3;
	int ys = y/3;
	
	sub[0] = solution[xs*3][ys*3];
	sub[1] = solution[xs*3+1][ys*3];
	sub[2] = solution[xs*3+2][ys*3];
	sub[3] = solution[xs*3][ys*3+1];
	sub[4] = solution[xs*3+1][ys*3+1];
	sub[5] = solution[xs*3+2][ys*3+1];
	sub[6] = solution[xs*3][ys*3+2];
	sub[7] = solution[xs*3+1][ys*3+2];
	sub[8] = solution[xs*3+2][ys*3+2];
	
	return sub;
}

void Sudoku::output(int matrixSol[9][9], string filename){
	ofstream out(filename);
	for (int i =0; i<9; i++){
		for (int j =0; j<9; j++){
			out << matrixSol[i][j] << ' ';
		}
		out << endl;
	}
	out << endl;
	out.close();
	
	cout << "Finish writing" << endl;
}

vector<int> Sudoku::getRest(){
	vector<int> s1(9,1);
	vector<int> s2(9,2);
	vector<int> s3(9,3);
	vector<int> s4(9,4);
	vector<int> s5(9,5);
	vector<int> s6(9,6);
	vector<int> s7(9,7);
	vector<int> s8(9,8);
	vector<int> s9(9,9);
	for (int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			if (matrix[i][j]!=0){
				if (matrix[i][j]==1){
					s1.pop_back();
				}
				else if(matrix[i][j] == 2){
					s2.pop_back();
				}
				else if(matrix[i][j] == 3){
					s3.pop_back();
				}
				else if(matrix[i][j] == 4){
					s4.pop_back();
				}
				else if(matrix[i][j] == 5){
					s5.pop_back();
				}
				else if(matrix[i][j] == 6){
					s6.pop_back();
				}
				else if(matrix[i][j] == 7){
					s7.pop_back();
				}
				else if(matrix[i][j] == 8){
					s8.pop_back();
				}
				else if(matrix[i][j] == 9){
					s9.pop_back();
				}
			}
		}
	}
	vector<int> list(begin(s1),end(s2));
	list.insert(end(list),begin(s2),end(s2));
	list.insert(end(list),begin(s3),end(s3));
	list.insert(end(list),begin(s4),end(s4));
	list.insert(end(list),begin(s5),end(s5));
	list.insert(end(list),begin(s6),end(s6));
	list.insert(end(list),begin(s7),end(s7));
	list.insert(end(list),begin(s8),end(s8));
	list.insert(end(list),begin(s9),end(s9));
	
	return list;
}

void Sudoku::bruteForce(string filename){
	vector<int> list = getRest();
	
	int solution[9][9];
	for (int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			solution[i][j] = matrix[i][j];
		}	
	}	
	next_permutation(list.begin(),list.end());
	
	int nx=0, ny=0,c=1;
	bool valid=false;
	
	while(!valid){
		//Fill out solution matrix
		int index = 0;
		for (int i = 0; i<9; i++){
			for (int j=0; j<9; j++){
				if(solution[i][j] == 0){
					solution[i][j] = list[index];
					index++;
				}
			}
		}
		if(isValid(solution)){
			valid = true;
			
		}
		else{
			for (int i = 0; i<9; i++){
				for (int j=0; j<9; j++){
					solution[i][j] = matrix[i][j];
				}	
			}	
			next_permutation(list.begin(),list.end());
		}
		
	}
	output(solution, filename);
}

void Sudoku::stochastic(string filename){
	vector<int> list = getRest();
	
	int solution[9][9];
	for (int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			solution[i][j] = matrix[i][j];
		}	
	}	
	random_shuffle(list.begin(), list.end());
	
	int nx=0, ny=0,c=1;
	bool valid=false;
	
	while(!valid){
		int index = 0;
		for (int i = 0; i<9; i++){
			for (int j=0; j<9; j++){
				if(solution[i][j] == 0){
					solution[i][j] = list[index];
					index++;
				}
			}
		}
		if(isValid(solution)){
			valid = true;
			
		}
		else{
			for (int i = 0; i<9; i++){
				for (int j=0; j<9; j++){
					solution[i][j] = matrix[i][j];
				}	
			}	
			random_shuffle(list.begin(), list.end());
		}
		
	}
	output(solution, filename);
}


void Sudoku::backtracking(int[9][9] presolution, int x , int y, int n){
	int solution[9][9];
	for (int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			solution[i][j] = presolution[i][j];
		}
	}

	while(ny < 9){
		if(solution[x][y] == 0){
			while(!isPromising(solution,x,y,c) && n<9){ 
			//if no solution found between 1-9 means no solution can be found for this matrix
				n++;
			}
			cout << "Still alive " << x << " " << y << endl;
			if(isPromising(solution,x,y,c)){
				solution[x][y] = c;
				ans[num][1] = nx;
				ans[num][2] = ny;
				ans[num][3] = c;
				num++;
			}
			else{
				solution[ans[num][1]][ans[num][2]] = 0;
				backtracking(solution, ans[num][1], ans[num][2], ans[num][3]);
				num--;
			}
			
		}
		else{
			if(nx < 8){
				nx++;
				n=1;
			}else if(nx = 8){
				nx = 0;
				ny++;
				n=1;
			}
		}
	}
output(solution, filename);
}

bool Sudoku::isValid(int matrixSol[9][9]){
	for (int i =0; i<9; i++){
			for (int j=0; j<9; j++){
				if (!isPromising(matrixSol, i, j, matrixSol[i][j])) return false;
			}
	}
	return true;
}

int main(int argc, const char *argv[]){
	Sudoku sdk = Sudoku(argv[1]);
	clock_t t1, t2;

	t1 = clock();
//	sdk.bruteForce("bruteSol.txt");
	t2 = clock();
	cout << "Output Brute Force solution, time: " << (float(t2) - float(t1)) << endl;
	
	t1 = clock();
	sdk.stochastic("stoSol.txt");
	t2 = clock();
	cout << "Output Brute Force solution, time: " << (float(t2) - float(t1)) << endl;
	
	t1 = clock();
//	sdk.backtracking("backTrackingSol.txt");
	t2 = clock();
	cout  << "Output Backtracking solution, time: "<< (float(t2) - float(t1)) << endl;
}

