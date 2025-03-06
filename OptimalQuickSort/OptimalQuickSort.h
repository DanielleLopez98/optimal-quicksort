
#ifndef OPTIMALQUICKSORT_OPTIMALQUICKSORT_H
#define OPTIMALQUICKSORT_OPTIMALQUICKSORT_H

#include <string>
/**
 * __________________________________________________________________________________
 * This class is for representing an integer that has an assocaited
 * alphabetized list which can be sorted by member function(s) into the optimal starting
 * order for quicksort performance
 * __________________________________________________________________________________
 */

class OptimalQuickSort {
    private:
        //Declare member variables
        int _numChars;
        std::string _alphaString;
        //Private recursive logic function for sort()
        void sort(int startIdx, int midIdx, int endIdx, std::string &resultString);
    public:
        //Default Constructor
        OptimalQuickSort();
        //General Constructor
        OptimalQuickSort(int numChars);
        //Create alphabet list
        std::string intToAlpha() const;
        //Public starter function to sort _alphaString optimally for quicksort
        std::string sort();


};


#endif //OPTIMALQUICKSORT_OPTIMALQUICKSORT_H
