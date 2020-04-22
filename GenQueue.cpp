//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "GenQueue.h"

GenQueue::GenQueue(){
    myQueue = new DoublyLinkedList();
    mSize = 100;
    front = 0;
    rear = -1;
    numElements = 0;
}

GenQueue::GenQueue(int maxSize){
    myQueue = new DoublyLinkedList();
    mSize = maxSize;
    front = 0;
    rear = -1;
    numElements = 0;
}

GenQueue::~GenQueue(){

}

void GenQueue::insert(T object){
    if(!isFull()){
        myQueue->insertBack(object);
        numElements++;
    }
}

T GenQueue::remove(T object){ //throw(QueueEmpty){
    ListNode *node = new ListNode();
    node->data = NULL;
    if(!isEmpty()){
        node = myQueue->removeFront();
        front++;
        numElements--;
    }
    return node;
}

T GenQueue::front(){ //throw(QueueEmpty){
    return myQueue->front();
}

int GenQueue::getSize(){
    return numElements;
}

bool GenQueue::isEmpty(){
    return (numElements == 0);
}

bool GenQueue::isFull(){
    return (numElements == mSize);
}

int main(){
    GenStack *myStack = new GenStack(10);

    myStack->push('R');
    myStack->push('e');
    myStack->push('n');
    myStack->push('e');

    cout << "popping :" << myStack->pop() << endl;
    cout << "peek-a-boo :" << myStack->peek() << endl;

    myStack->push('F');
    cout << "peek-a-boo :" << myStack->peek() << endl;

    while(!myStack->isEmpty()){
        cout << "popping :" << myStack->pop() << endl;
    }

    cout << "Is stack empty? " << myStack->isEmpty() << endl;

    delete myStack;
    return 0
}
