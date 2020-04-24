#include "ListNode.h"

//default constructor
template<class T>
ListNode<T>::ListNode(){
    prev = NULL;
    next = NULL;
}

//overload constructor
template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    prev = NULL;
    next = NULL;
}

//deconstructor
template<class T>
ListNode<T>::~ListNode(){
    prev = NULL;
    next = NULL;
}


template class ListNode<Student>;
template class ListNode<Window>;
