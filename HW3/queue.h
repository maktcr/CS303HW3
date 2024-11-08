#pragma once
#include <iostream>
using namespace std;

//node structure for the linked list
template <typename Type>
struct Node {
    Type data;
    Node* next;
    Node(Type value) : data(value), next(nullptr) {}
};

//queue data structure using linked list
template <typename Type>
class Queue {
private:
    Node<Type>* head; 
    Node<Type>* tail;  
    int num;

    void copyFrom(const Queue& other) {
        Node<Type>* current = other.head;
        while (current) {
            push(current->data);
            current = current->next;
        }
    }

public:

    //constructor
    Queue() : head(nullptr), tail(nullptr), num(0) {}

    //destructor
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
 
    void push(Type value);
    void pop();
    Type front();
    int size();
    bool empty();
    void move_to_rear();
};


template <typename Type>
void Queue<Type>::push(Type value) {
    //create a new node
    Node<Type>* newNode = new Node<Type>(value);
    //if a tail already exists, set tail next to the new node
    if (tail) {
        tail->next = newNode;
    }
    //if a tail doesnt exist then a head doesnt exist. set the head to new node
    else {
        head = newNode;
    }
    //set tail to new node and incriment num
    tail = newNode;
    num++;
}

// Removes an element from the front of the queue
template <typename Type>
void Queue<Type>::pop() {
    //if queue is empty, alert the user and exit the function
    if (empty()) {
        cout << "Error: Queue is empty" << endl;
        return;
    }

    //create a temp node with the current head
    Node<Type>* temp = head;
    //set the new head to the second item in the list
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    //delete the temp node holding the head, and decrement num
    delete temp;
    num--;
}

// Returns the front element of the queue
template <typename Type>
Type Queue<Type>::front() {
    if (empty()) {
        cout << "Error: Queue is empty" << endl;
        return Type();
    }
    return head->data;
}

//returns the number of elements in the queue
template <typename Type>
int Queue<Type>::size() {
    return num;
}

//checks if the queue is empty
template <typename Type>
bool Queue<Type>::empty() {
    //returns true if num = 0, else will return false
    return num == 0;
}

//moves the element currectly at the front of the queue to the rear
template <typename Type>
void Queue<Type>::move_to_rear() {
    //if queue is empty, alert the user and exit the function
    if (empty()){
        cout << "Error: Queue is empty" << endl;
    }
    else {
        //push the item at the front to the rear, then pop front item 
        push(front());
        pop();
    }
}