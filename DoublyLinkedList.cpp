//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "DoublyLinkedList.h"

//default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    // front = new ListNode<T>();
    // back = new ListNode<T>();
    // front->next = back;
    // back->prev = front;
    front = NULL;
    back = NULL;
    size = 0;
}

//deconstructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(!isEmpty()){
        removeFront();
    }
    delete front;
    delete back;
}

template<class T>
T DoublyLinkedList<T>::peek(){
    return front->data;
}

template<class T>
int DoublyLinkedList<T>::search(T object){
    int pos = -1;
    ListNode<T> *curr = front;
    while(curr != NULL){
        pos++;
        if(curr->data == object)
            break;
        else
            curr = curr->next;
    }
    if(curr == NULL)
        pos = -1;
    return pos;
}

template<class T>
void DoublyLinkedList<T>::insertFront(T object){
    ListNode<T> *node = new ListNode<T>(object);
    if(isEmpty())
        back = node;
    else{
        front->prev = node;
        node->next = front;
    }
    front = node;
    size++;
}

template<class T>
void DoublyLinkedList<T>::insertBack(T object){
    ListNode<T> *node = new ListNode<T>(object);
    if(isEmpty())
        front = node;
    else{
        back->next = node;
        node->prev = front;
    }
    back = node;
    size++;
}

template<class T>
T DoublyLinkedList<T>::removeFront(){
    ListNode<T> *tempNode = front;

    if(isEmpty()){}
        // ERROR

    //SEG FAULT in this if-else block, can only remove once
    if(front->next == NULL)
        back = NULL;
    else
        front->next->prev = NULL;

    front = front->next;
    tempNode->next = NULL;
    T temp = tempNode->data;
    size--;
    delete tempNode;
    return temp;
}

template<class T>
T DoublyLinkedList<T>::removeAtPos(int pos){

    if(pos >= size){}
        // ERROR

    int idx = 0;
    ListNode<T> *curr = front;
    ListNode<T> *previous = front;
    while(idx != pos){
        previous = curr;
        curr = curr->next;
        idx++;
    }
    previous->next = curr->next;
    curr->next = NULL;
    T temp = curr->data;
    delete curr;
    size--;
    return temp;
}

template<class T>
T DoublyLinkedList<T>::removeBack(){
    ListNode<T> *tempNode = back;

    if(isEmpty()){}
        // ERROR

    if(back->prev == NULL){
        front == NULL;}
    else
        back->prev->next = NULL;

    back = back->prev;
    tempNode->prev = NULL;
    T temp = tempNode->data;
    size--;
    delete tempNode;
    return temp;
}

template<class T>
T DoublyLinkedList<T>::remove(T object){
    ListNode<T> *curr = front;
    while(curr->data != object){
        curr = curr->next;
        if(curr == NULL)
            return -1;
    }

    if(curr == front)
        front = curr->next;
    else
        curr->prev->next = curr->next;

    if(curr == back)
        back = curr->prev;
    else
        curr->next->prev = curr->prev;

    curr->next = NULL;
    curr->prev = NULL;
    int temp = curr->data;
    size--;
    delete curr;

    return temp;
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

template class DoublyLinkedList<char>; // debugging purposes only
