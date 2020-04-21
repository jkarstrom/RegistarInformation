#include "ListNode.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

template<class T>

class DoublyLinkedList{
public:
    DoublyLinkedList();//default constructor
    ~DoublyLinkedList();//deconstructor

    //core functions
    int search(T data);
    void insert(T data);
    void advance();
    void delete(T data);

    //aux functions
    T front();
    T back();

private:
    //vars
    ListNode *front;
    ListNode *back;
    ListNode *cursor;
};
