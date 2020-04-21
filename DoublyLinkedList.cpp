//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "DoublyLinkedList.h"

//default constructor
DoublyLinkedList::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    cursor = front;
    size = 0;
}

//deconstructor
DoublyLinkedList::~DoublyLinkedList(){
    front = NULL;
    cursor = NULL;
}

T DoublyLinkedList::search(T object){
    int pos = -1;
    ListNode *curr = front;
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

void DoublyLinkedList::insertFront(T object){
    ListNode *node = new ListNode(object);
    if(isEmpty())
        back = node;
    else{
        front->prev = node;
        node->next = front;
    }
    front = node;
    size++;
}

void DoublyLinkedList::insertBack(T object){
    ListNode *node = new ListNode(object);
    if(isEmpty())
        front = node;
    else{
        back->prev = node;
        node->next = front;
    }
    back = node;
    advance();
    size++;
}

void DoublyLinkedList::advance(){
    cursor = cursor->next;
}

T DoublyLinkedList::removeFront(){
    ListNode *tempNode = front;
    if(front->next == NULL)
        back == NULL;
    else
        front->next->prev = NULL;
    front = front->next;
    tempNode->next = NULL;
    T temp = tempNode->data;
    size--;
    delete tempNode;
    return temp;
}

T DoublyLinkedList::removeAtPos(int pos){
    int idx = 0;
    ListNode *curr = front;
    ListNode *previous = front;
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

T DoublyLinkedList::removeBack(){
    ListNode *tempNode = back;
    if(back->prev == NULL)
        front == NULL;
    else
        back->prev->next = NULL;
    back = back->prev;
    cursor = back;
    tempNode->prev = NULL;
    T temp = tempNode->data;
    size--;
    delete tempNode;
    return temp;
}

T DoublyLinkedList::remove(T object){
    ListNode *curr = front;
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

    cursor = back;
    curr->next = NULL;
    curr->prev = NULL;
    int temp = curr->data;
    size--;
    delete curr;

    return temp;
}

unsigned int DoublyLinkedList::getSize(){
    return size;
}

bool DoublyLinkedList::isEmpty(){
    return (size == 0);
}

T DoublyLinkedList::front(){
    return cursor->next;
}

T DoublyLinkedList::back(){
    return cursor->data;
}
