#include <iostream>

template<class T>

class ListNode{
public:
    T data;
    ListNode *prev;
    ListNode *next;

    ListNode();
    ListNode(T d);
    ~ListNode();
};
