==Info==
Program name: program3
Source files: Program3.cpp Sequences.cpp Sequences.h

==Command line example==
Prompt>> program3 <filex.txt> <filey.txt> <output3.txt>

==Description==
Write a program that solves the LCS problem by the top-down dynamic programming 
approach -  recursively computing the length of a longest common subsequence 
with memoization. The input as before are the files "filex" and filey. The output 
is written into "output3.txt". 


==Methods used==
findMax():
Find max integer between 2.
param int a, b: 2 integers to be compared
return int: the one that is bigger

topDown():
The main function that build a matrix to do memoization and then start the recursion.
param Sequences obj: contains 2 sequences that will be compared. 
return int: the length of the LCS.

_topDown():
Subfunction that can be recursively called. It will either start a new recursion
to compute the length or simply return an existing length.
param int **matrix: the memoization
param int x, y: the index of number 
param Sequences obj: contains 2 sequences that is being compared. 
return int: the length so far.

==Class used==
Sequences: 
This class contains 2 sequences that will be compared. 
param char *filex: contains char array from "filex.txt"
param char *filey: contains char array from "filey.txt"
param int ix: the length of filex
param int iy: the lenght of filey

==Analysis==
Computation time: O(mn)

