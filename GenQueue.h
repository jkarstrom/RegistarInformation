#include "DoublyLinkedList.h"

template<class T>

class GenQuene{
public:
    GenQuene();
    ~GenQuene();

    insert(object);
    void remove(object) throw(QueueEmpty);
    T front() throw(QueueEmpty);
    int size();
    bool isEmpty();

private:
    DoublyLinkedList myList;
    int size;

};
