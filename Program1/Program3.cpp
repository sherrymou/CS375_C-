#include <iostream>
#include <fstream>
#include <time.h>
#include "Sequences.h"
using namespace std;

int findMax(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}

int _topDown(int **matrix, int x, int y, Sequences obj){
	if (x<0 || y<0) return 0;
	if (matrix[x][y]<0){
		if (obj.filex[x]==obj.filey[y]) {
			matrix[x][y] = 1 + _topDown(matrix, x-1, y-1, obj);
		}else{
			matrix[x][y] = findMax(_topDown(matrix, x-1, y,obj), _topDown(matrix, x, y-1, obj));
		}
	}else{
		return matrix[x][y];
	}
}


int topDown(Sequences obj){
	//Initiate a memoization matrix
	int **matrix;
	matrix = new int*[obj.ix];
	for (int i=0; i<obj.ix; i++){
		matrix[i] = new int[obj.iy];
	}
	for (int i=0; i<obj.ix; i++){
		for (int j=0; j<obj.iy; j++){
			matrix[i][j] = -1;
		}
	}
	
	return _topDown(matrix, obj.ix-1, obj.iy-1, obj);
}

int main(int argc, const char* argv[]){
	clock_t tb,ta;
	tb = clock();
	Sequences obj = Sequences(argv[1], argv[2]);
    
    int length = topDown(obj);

	ta = clock();
	float runningTime = (float(ta) - float(tb));

	ofstream out(argv[3]);
	out << "Length: " << length <<endl;
	out << "Running Time: " << runningTime << endl;
	out.close();
}
