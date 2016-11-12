#include <iostream>
#include <fstream>
#include <time.h>
#include "Sequences.h"
using namespace std;

struct Trace;
Trace bottomUp(Sequences obj);
int** copyMatrix(int matrix[100][100]);
char* traceChar(char *arr, char *seq, char indicator[100][100], int x, int y, int pos);

struct Trace{
	int length;
	int **matrix;
	char *array;
};

Trace bottomUp(Sequences obj){
	int matrix[100][100];
	char indicator[100][100];
	for (int i = 0; i<obj.ix; i++){
		matrix[i][0] = 0;
	}
	for (int i = 0; i<obj.iy; i++){
		matrix[0][i] = 0;
	}
	for (int i = 1; i<=obj.ix; i++){
		for (int j=1; j<=obj.iy; j++){
			if (obj.filex[i-1] == obj.filey[j-1]){
				matrix[i][j]=matrix[i-1][j-1]+1;
				indicator[i][j] = 'b'; //left-up
			}else if (matrix[i-1][j]>=matrix[i][j-1]){
				matrix[i][j] = matrix[i-1][j];
				indicator[i][j] = 'u'; //up
			}else{
				matrix[i][j] = matrix[i][j-1];
				indicator[i][j] = 'l'; // left
			}
		}
	}
	Trace retVal;
	retVal.length = matrix[obj.ix][obj.iy];
	if (obj.ix <= 10 && obj.iy <= 10){
		retVal.matrix = copyMatrix(matrix);
		char *arr = new char[11];
		retVal.array = traceChar(arr, obj.filex, indicator, obj.ix, obj.iy,0);
	}
	return retVal;
}


int** copyMatrix(int matrix[100][100]){
	int **retVal;
	retVal = new int*[11];
    for (int i= 0; i<11; i++){
          retVal[i] = new int[11];
    }

	for (int i = 0; i<11; i++){
		for (int j=0; j<11; j++){
			retVal[i][j] = matrix[i][j];
		}
	}
	return retVal;
}

char* traceChar(char *arr, char *seq,  char indicator[100][100], int x, int y, int pos){
	if (x<=0||y<=0) {
		arr[pos] = '\0';
		return arr;
	}
	if (indicator[x][y] == 'b'){
		arr[pos] = seq[x-1];
		pos ++;
		return traceChar(arr, seq, indicator, x-1, y-1, pos);
	}else if (indicator[x][y] == 'u'){
		return traceChar(arr, seq, indicator, x-1, y, pos);
	}else if (indicator[x][y] == 'l'){
		return traceChar(arr, seq, indicator, x, y-1, pos);
	}else{
		cout << "Error: traceChar " << endl;
		return arr;
	}
}

int main(int argc, const char *argv[]){
	clock_t tb,ta;
	tb = clock();
	Sequences obj = Sequences(argv[1], argv[2]);
	Trace result = bottomUp(obj);

	int length = result.length;
	ofstream out(argv[3]);
	if (obj.ix > 10 || obj.iy > 10){
		ta = clock();

		float runningTime = (float(ta)-float(tb));
		out <<"The length of the LCS is " << length << endl;
		out << "The Running Time is " << runningTime << endl;
	}else{
		int** matrix = result.matrix;
		char* charArray = result.array;
		
		//Print x axis
		out << "    ";
		for (int i =0; i<obj.iy;i++){
			out<< obj.filey[i]<<" ";
		}
		out<<endl;
		
		//Print first row of 0s
		out<<"  ";
		for (int i=0; i<=obj.iy; i++){
			out <<matrix[i][0] << " ";
		}
		out << endl;
		
		//Print the rest of the table
		for (int i=1; i<=obj.ix;i++){
			out << obj.filex[i-1] << " ";
			for (int j=0; j<=obj.iy; j++){
				 out << matrix[i][j]<<" ";
			}
			out << endl;
		}
		
		//Print the LCS
		out << "The LCS: ";
			int counter = 0;
			while(result.array[counter]!= '\0'){
				counter++;
			}
			for (int i=counter-1; i>=0; i--){
				out<<result.array[i];
			}
			out << endl;

		ta = clock();
		float runningTime = (float(ta)-float(tb));
		out << "Running Time: " << runningTime << endl;
	}
	out.close();
}
