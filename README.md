# Optimal Quicksort
This program takes one positive int less than or equal to 26 as an argument (argv[1]). 
It then converts the int into an alphabetized list of letters (ex: 3 -> ABC, 7 -> ABCDEFG, etc.)
It then takes the list and converts it into an order that is optimal for quicksort, that is, 
the leftmost element of every sublist at each step of quicksort is always the median element of the sublist. (ex: 3-> BAC, 7-> DACBFEG)
A detailed explanation of how this is done and why the output order of characters is optimal for quicksort can be found in the comments of OptimalQuickSort.cpp

# Instructions
Compile and run this program (main is in OptimalQuickSort.cpp) with 1 argument that is a positive int less than or equal to 26.

# Details
This code was created for the class CS 6420 (Advanced Algorithms) at Weber State University. All code in this project is my own.
I thought of and implemented this algorithm independently.

