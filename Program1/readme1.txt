==Info==
Program name: program1
Source files: Program1.cpp Sequences.cpp Sequences.h

==Command line example==
Prompt>> program1 <filex.txt> <filey.txt> <output1.txt>

==Description==
Write a program that solves the Longest Common Subsequence (LCS) problem by the 
bottom-up dynamic programming approach. The inputs to the program are two files 
"filex.txt" and "filey.txt". The output is written into "output1.txt".

==Data Structure==
struct Trace:
A container that holds the result to be output
variable: int length: length of the LCS
variable: int **matrix: matrix that contains the length of each steps
variable: char *array: an array of common characters

==Methods used==
bottomUp():
Main function that conduct the program
param Sequences obj: contain 2 sequences that will be compared
return Trace: holds the results

copyMatrix():
Copy the matrix of lengths to a smaller (row, col <=10) matrix to be printed
param int matrix[100][100]
return int**: smaller int array

traceChar():
To trace the common characters
param char *arr: the array that contains common characters
param char *seq: one of the sequence that extract characters from
param char indicator[100][100]: a matrix indicate the direction of LCS 
param int x,y: the index that in the indicator matrix
param int pos: the next empty index in arr;
return char*: array that contains common characters

==Class used==
Sequences: 
This class contains 2 sequences that will be compared. 
param char *filex: contains char array from "filex.txt"
param char *filey: contains char array from "filey.txt"
param int ix: the length of filex
param int iy: the lenght of filey

==Analysis==
Computation time: O(mn)


