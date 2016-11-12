==Info==
Program name: program2
Source files: Program2.cpp Sequences.cpp Sequences.h

==Command line example==
Prompt>> program2 <filex.txt> <filey.txt> <output2.txt>

==Description==
This program solves the LCS problem by recursively computing the length of a 
longest common subsequence (without memoization). The input as before are the 
files "filex" and "filey". The output is written into "output2.txt". 

==Methods used==
findLength():
Start to find the LCS
param Sequences obj: the sequences that need to be compared
return int: the length of the total LCS

_findLength():
Subfunction that can be resursively called
param char *filex: contains char array from "filex.txt"
param char *filey: contains char array from "filey.txt"
param int i: the length of filex
param int j: the lenght of filey
return int: the length of the sub LCS

==Class used==
Sequences: 
This class contains 2 sequences that will be compared. 
param char *filex: contains char array from "filex.txt"
param char *filey: contains char array from "filey.txt"
param int ix: the length of filex
param int iy: the lenght of filey

==Analysis==
Computation time: O(2^n) (if n == m)


