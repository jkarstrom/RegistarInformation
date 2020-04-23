//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "ListNode.h"
template<class T>

class DoublyLinkedList{
public:
    DoublyLinkedList();//default constructor
    ~DoublyLinkedList();//deconstructor

    //core functions
    T peek();
    int search(T object);
    void insertFront(T object);
    void insertBack(T object);
    T removeFront();
    T removeAtPos(int pos);
    T removeBack();
    T remove(T object);

    unsigned int getSize();
    bool isEmpty();

private:
    //vars
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
};

#endif
