//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include "Window.h"
using namespace std;

template<class T>

class ListNode{
public:

    ListNode();//default constructor
    ListNode(T d);//overload constructor
    ~ListNode();//deconstructor

    //vars
    T data;
    ListNode *prev;
    ListNode *next;
};

#endif
