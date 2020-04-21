//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "ListNode.h"

template<class T>

class DoublyLinkedList{
public:
    DoublyLinkedList();//default constructor
    ~DoublyLinkedList();//deconstructor

    //core functions
    int search(T object);
    void insertFront(T object);
    void insertBack(T object);
    T removeFront();
    T removeAtPos(T object)
    T removeBack();
    T remove(int pos);

    unsigned int getSize();
    bool isEmpty();

    //aux functions
    T front();
    T back();

private:
    //vars
    ListNode *front;
    ListNode *back;
    ListNode *cursor;
    unsigned int size;

    void advance();
};
