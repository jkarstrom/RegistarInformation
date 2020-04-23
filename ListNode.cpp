#include "ListNode.h"

template<class T>
ListNode<T>::ListNode(){
    // data = 0;
    prev = NULL;
    next = NULL;
}

template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    prev = NULL;
    next = NULL;
}

template<class T>
ListNode<T>::~ListNode(){
    prev = NULL;
    next = NULL;
}


template class ListNode<Student>;
template class ListNode<Window>;
