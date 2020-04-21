//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "DoublyLinkedList.h"

template<class T>

class GenQueue{
public:
    GenQueue();//default constructor
    GenQueue(int maxSize); //overloaded constructor
    ~GenQueue();//deconstructor

    //core functions
    void insert(T object);
    T remove(T object); //throw(QueueEmpty);
    T front(); //throw(QueueEmpty);

    //aux functions
    int getSize();
    bool isEmpty();
    bool isFull();

private:
    //vars
    DoublyLinkedList myQueue;
    int front;
    int back;
    int size;
    int numElements;
};
