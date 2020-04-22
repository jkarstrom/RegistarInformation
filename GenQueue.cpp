//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "GenQueue.h"

template<class T>
GenQueue<T>::GenQueue(){
    myList = new DoublyLinkedList<T>();
    size = 100;
    front = 0;
    rear = -1;
    numElements = 0;
}

template<class T>
GenQueue<T>::GenQueue(int maxSize){
    myList = new DoublyLinkedList<T>();
    size = maxSize;
    front = 0;
    rear = -1;
    numElements = 0;
}

template<class T>
GenQueue<T>::~GenQueue(){

}

template<class T>
void GenQueue<T>::insert(T object){
    if(!isFull()){
        myList->insertBack(object);
        numElements++;
    }
}

template<class T>
T GenQueue<T>::remove(){ //throw(QueueEmpty){
    T temp;
    if(!isEmpty()){
        temp = myList->removeFront();
        front++;
        numElements--;
    }
    return temp;
}

template<class T>
T GenQueue<T>::peek(){ //throw(QueueEmpty){
    return myList->peek();
}

template<class T>
int GenQueue<T>::getSize(){
    return numElements;
}

template<class T>
bool GenQueue<T>::isEmpty(){
    return (numElements == 0);
}

template<class T>
bool GenQueue<T>::isFull(){
    return (numElements == size);
}

template class GenQueue<char>; // debugging purposes only
