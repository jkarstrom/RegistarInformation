#include "DoublyLinkedList.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

template<class T>

class GenQuene{
public:
    GenQuene();//default constructor
    ~GenQuene();//deconstructor

    //core functions
    insert(object);
    void remove(object) throw(QueueEmpty);
    T front() throw(QueueEmpty);

    //aux functions
    int size();
    bool isEmpty();

private:
    //vars
    DoublyLinkedList myList;
    int size;

};
