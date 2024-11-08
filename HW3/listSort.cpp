#include "listSort.h"

void listSort(queue<int>& q) {
    queue<int> sortedQueue;
    queue<int> tempQueue;

    //process each element in the original queue
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        //move elements from the sorted queue to the original queue that are greater than current
        while (!sortedQueue.empty() && sortedQueue.back() > current) {
            tempQueue.push(sortedQueue.front());
            sortedQueue.pop();
        }

        //add the current element in the correct position in the sorted queue
        sortedQueue.push(current);


        while (!tempQueue.empty()) {
            sortedQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    //transfer the sorted elements back to the original queue
    while (!sortedQueue.empty()) {
        q.push(sortedQueue.front());
        sortedQueue.pop();
    }

    
    cout << "Queue after sorting: ";
}



