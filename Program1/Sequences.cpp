#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "Sequences.h"
using namespace std;

Sequences::Sequences(){}

Sequences::Sequences(const char* filextxt, const char* fileytxt){
	string temp;

	ifstream file1(filextxt);
	getline(file1, temp);
	filex = new char[temp.length()+1];
	strcpy(filex, temp.c_str());	
//	cout <<filex<<endl; //debug
	ix = temp.length();
	file1.close();

	ifstream file2(fileytxt);
	getline(file2, temp);
	filey = new char[temp.length()+1];
	strcpy(filey, temp.c_str());	
//	cout <<filey<<endl; //debug
	iy = temp.length();
	file2.close();

}
