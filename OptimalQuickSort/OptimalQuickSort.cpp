// Dani Lopez
// CS 6420
// Assignment #1
// Dr. Rague
// Due: 1/25/25
// Version: 1.0
// -----------------------------------------------------------------
// This program takes an int, converts the int into an associated
// vector of alphabetic characters (ie 3 -> ABC, 5-> ABCDE, etc.)
// and arranges it in the optimal order for quicksort runtime.
// -----------------------------------------------------------------


#include "OptimalQuickSort.h"
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

/**
 * _______________________________________________________________________
 * Default constructor:
 * This function creates an object of the OptimalQuickSort class, initializing
 * the the member variable (_numChars) to a default value of 1 in the absence
 * of a user provided integer. It also calls intToAlpha to create the string
 * of alphabet characters based on the value for _numChars (which in this case
 * is just "A");
 * _______________________________________________________________________
 */
OptimalQuickSort::OptimalQuickSort(){
    this->_numChars = 1;
    this->_alphaString = intToAlpha();
}

/**
 * _______________________________________________________________________
 * General constructor:
 * This function creates and object of the OptimalQuickSort class, initializing
 * the only member variable (_numChars) to the integer the user entered.
 * It also calls intToAlpha to create the string
 * of alphabet characters based on the value for _numChars
 * _______________________________________________________________________
 */
OptimalQuickSort::OptimalQuickSort(int numChars){
    this->_numChars = numChars;
    this->_alphaString = intToAlpha();
}

/**
 * _______________________________________________________________________
 * intToAlpha:
 * This function uses the int member variable _numChars to create and return
 * an alphabetically ordered string of characters of length _numChars
 * _______________________________________________________________________
 */
std::string OptimalQuickSort::intToAlpha() const{
    std::string alphaString; //create an empty string
    for(int i = 0; i < this->_numChars; i++){ //for number of iterations as specified by _numChars
        alphaString.push_back(i+65); //append ascii character 65 + i to the string (when i is 0 the ASCII character is A)
    }
    return alphaString; //returns string
}

/***
 *____________________________________________________________
 * sort():
 * This function is necessary to start the private recursive logic function
 * sort(int startIdx, int midIdx, int endIdx, std::string &resultsString)
 * it also returns the final result string after the recursive logic function returns
 * ___________________________________________________________
 */
std::string OptimalQuickSort::sort(){
    int startIdx = 0; //The starting index of _alphaString is 0
    int midIdx = floor((this->_numChars - 1)/2); //The median (or near median in the case of an even _numChar) index of _alphaString is given by the floor of the number of characters - 1divided by 2
    int endIdx = this->_numChars - 1; //The ending index of _alphaString is given by the number of characters - 1

    std::string resultString(_numChars, ' '); //Create a string to hold the result, consisting entirely of spaces for as many chars as there are in _alphaString
    resultString[0] = this->_alphaString[midIdx]; //Set the leftmost index in the result string to the character at the median index in _alphaString

    sort(startIdx, midIdx, endIdx, resultString); //run the private recursive logic function
    return resultString; //upon returning
}

/***
 *__________________________________________________________________________________________________________________________________________
 * sort():
 * This is the recursive logic function that fills resultString with the characters in _alphaString in the optimal order for quick sort
 *
 * Here is the pattern that describes the optimal ordering for QuickSort and is implemented in the function below
 * This is the pattern provided that in the QuickSort algorithm:
 *      1) The leftmost element is always chosen as pivot
 *      2) the i pointer moves right until finding an element greater than the pivot, the j pointer moves left until finding an element less than the pivot, and
 *         at where i is farther right than j and j is less than i, the pivot (leftmost element) swaps with the element at j
 *
 * Pattern that is made with the recursive logic below:
 *  - The leftmost element in the optimal list is the median of the entire ascending ordered list (performed by the starter function)
 *
 *  ------- Everything below this line is recursive-----------------------------------------------------------------------------------
 *  - For the ascending ordered list of elements less than the previous median (left side):
 *      - the median of this left side ascending ordered list is placed in the optimal list at the original index of the previous median in the ascending order list
 *
 *  - For the ordered list of elements greater than  the previous median (right side):
 *      - the median of this right side ascending ordered list is placed in the optimal list at the index just to the right of the previous median in the ascending order list
 * --------------------------------------------------------------------------------------------------------------------------------------
 *  the optimal list is passed by reference so it is altered in the calling public starter function, and is returned in that function
 *  --------------------------------------------------------------------------------------------------------------------------------------
 *  The reason why we can't simply keep taking the median and moving it to the leftmost spot of its partition is because of the swap with j,
 *  and while this algorithm is messier, it accounts for the swap so that after each partition including the swap, the median ends up on the left
 *  even though it doesn't necessarily start there in the optimally ordered list
 * __________________________________________________________________________________________________________________________________________
 */

void OptimalQuickSort::sort(int startIdx, int midIdx, int endIdx, std::string &resultString) {

    //Base Case: If the start index becomes greater than the ending index, return from the function
    if (startIdx > endIdx) {
        return;
    }

    int leftStartIdx = startIdx; //set the left subsection start index to the starting index of the whole section
    int leftEndIdx = midIdx - 1; //set the left subsection end index to the index directly to the left of median index of the whole section
    if (leftStartIdx <= leftEndIdx) { //provided the start index has not gone past the end index
        int leftMidIdx = leftStartIdx + floor(((leftEndIdx - leftStartIdx)/2)); //find median index of this left subsection (the index within the entire _alphaString list as given by the  leftStartIndex + preceding the division)
        resultString[midIdx] = this->_alphaString[leftMidIdx]; //set the  median index of the whole section in the resultString to the character at the median index of this left subsection
        sort(leftStartIdx, leftMidIdx, leftEndIdx, resultString); //recursively call this function with the leftStartIdx for the start index, the leftMidIdx for the median index, and the leftEndIdx fot the end index
    }
    int rightStartIdx = midIdx + 1; //set the right subsection start index to the index directly to the right of the median of the whole section
    int rightEndIdx = endIdx; //set the right subsection end index to the end index of the whole section
    if (rightStartIdx <= rightEndIdx) {
        int rightMidIdx = rightStartIdx + floor(((rightEndIdx - rightStartIdx) / 2)); //find median index of this right subsection (the index within the entire _alphaString list as given by the rightStartIndex + preceding the division)
        resultString[midIdx + 1] = this->_alphaString[rightMidIdx]; //set the index directly right fo the median index of the whole section in the resultString to the character at the median index of this right subsection
        sort(rightStartIdx, rightMidIdx, rightEndIdx, resultString); //recursively call this function with the rightStartIdx for the start index, the rightMidIdx for the median index, and the rightEndIdx for the end index
    }
}
/**
 * _______________________________________________________________________________________________________
 * Main Program
 * This program takes one int as a command line argument and creates an object of the OptimalQuickSort class
 * to convert the int into an alphabetized string of that length (ie 5 -> ABCDE, 8-> ABCDEFGH. Then via the
 * class function sort() the alphabetized list is sorted into an order that is optimal for quicksort and output to the screen
 * ________________________________________________________________________________________________________
 */

int main(int argc, char* argv[]){
    //Check that user entered an argument
    if(argc < 2){
        //If not display error message and usage instructions and exit
        std::cerr << "Usage: " << argv[0] << "int between 1 and 26" << std::endl;
        return 1;
    }
    int numChars = atoi(argv[1]); //convert command line argument to int and store in numChars

    //Check that the user entered a value between 1 and 26
    if(numChars < 1 || numChars > 26){
        //If not display error message and usage instructions and exit
        std::cerr << "Usage: " << argv[0] << "int between 1 and 26" << std::endl;
        return 1;
    }

    OptimalQuickSort opt(numChars); //create OptimalQuickSort object using general constructor with an input of numchars

    std::cout << argv[1] << " ---> Result: " << opt.sort() << std::endl; //output the string of alphabet characters sorted for optimal runtime in quicksort

    return 0;
}