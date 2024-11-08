#include "queue.h"
#include "recursiveLinearSearch.h"
#include "listSort.h"

int main()
{
    //QUESTION ONE
    //includes queue.h 
    //
    //instantiate the queue with integers and push 10 values into the queue
    Queue<int> myQueue;
    myQueue.push(2);
    myQueue.push(4);
    myQueue.push(6);
    myQueue.push(8);
    myQueue.push(10);
    myQueue.push(1);
    myQueue.push(3);
    myQueue.push(5);
    myQueue.push(7);
    myQueue.push(9);

    //write a new queue function called move_to_rear that moves the element currently at
    //the front of the queue to the rear of the queue.
    //2 should now appear at the end of the queue when it is printed
    myQueue.move_to_rear();

    //display all the elemnts in a queue using just the queue functions push, pop, front, and size
    //iterate through the queue, stopping when size = 0 (the queue is empty)
    cout << "The queue is :  ";
    while (myQueue.size() > 0) {
        //use front() to display the value at the front, then use pop to delete that value
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    cout << "----------------------------";
    cout << endl;


    //QUESTION TWO
    //includes recursiveLinearSearch.h and recursiveLinearSearch.cpp 
    //
    //
    //declare the vector with some random numbers.
    vector<int> vect = { 1, 1, 2, 3, 4, 5, 8, 1, 9 };
    int num;
    for (int i = 0; i < vect.size(); i++) {
        cout << vect.at(i) << " ";
    }
    cout << endl;

    //Get a number to search for from the user.
    cout << "Enter a number to find the last instance of that number in the vector: " << endl;
    cin >> num;
    
    //call findLast, which returns the index where the number was found.
    int index = findLast(vect, num);

    //findLast returns -1 if number is not found, notify the user if so.
    if (index != -1) {
        //if number is found, return it and the index where it was found to the user.
        cout << "The last instance of " << num << " was found at index " << index << "." << endl;
    }
    else {
        cout << "The number " << num << " was not found in the vector." << endl;
    }
    cout << endl;
    cout << "----------------------------";
    cout << endl;


    //QUESTION THREE
    //includes listSort.h and listSort.cpp
    //declare a queue of ints and add some elements
    queue<int> q;

    q.push(3);
    q.push(4);
    q.push(2);
    q.push(1);


    //print the queue before sorting.
    cout << "Queue before sorting: ";
    queue<int> tempQueue = q; 
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    //sort the queue.
    listSort(q);

    //print the Queue after sorting.
    cout << "Queue after sorting: ";
    tempQueue = q;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}



