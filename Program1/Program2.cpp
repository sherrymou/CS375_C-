#include <iostream>
#include <fstream>
#include <time.h>
#include "Sequences.h"
using namespace std;

int _findLength(char *filex, char *filey, int i, int j){
	if (i<0 || j <0) {
		return 0;
	}
	if (filex[i] == filey[j]){
		return _findLength(filex, filey, i-1, j-1)+1;
 	}else if (_findLength(filex, filey, i-1, j) < _findLength(filex, filey, i, j-1)){
		return _findLength (filex, filey, i, j-1);
	}else{
		return _findLength (filex, filey, i-1, j);
	}
}

int findLength(Sequences obj){
	return _findLength(obj.filex, obj.filey, obj.ix-1, obj.iy-1);
}

int main(int argc, const char* argv[]){
	clock_t tb,ta;
	tb = clock();
	Sequences obj = Sequences(argv[1], argv[2]);
	int length = findLength(obj);
	float runningTime = (float(ta) - float(tb));
	ta = clock();
	ofstream out(argv[3]);
	out << "Length: " << length <<endl;
	out << "Running Time: " << runningTime << endl;
	out.close();
}
