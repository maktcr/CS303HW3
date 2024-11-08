#include "recursiveLinearSearch.h"

int findLast(const std::vector<int>& vect, int num, int index) {
    //initialize index on first call to start from the last element
    if (index == -1) {
        index = vect.size() - 1;
    }

    //base case: if index is out of bounds, return -1 (target not found)
    if (index < 0) {
        return -1;
    }

    //check the current element to see if it matches the target
    if (vect[index] == num) {
        //return index if target is found
        return index;  
    }

    // Recursive call moving one step back
    return findLast(vect, num, index - 1);
}