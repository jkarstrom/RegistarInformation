#include "ListNode.h"

template<class T>

class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    int search(T data);
    void insert(T data);
    void advance();
    void delete(T data);

    T front();
    T back();

private:
    ListNode *front;
    ListNode *back;
    ListNode *cursor;
};
