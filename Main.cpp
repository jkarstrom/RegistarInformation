#include "DoublyLinkedList.h"

int main(int argc, char ** argv){

    DoublyLinkedList<char> *myList = new DoublyLinkedList<char>();
    myList->insertFront('3');
    myList->insertFront('2');
    myList->insertFront('1');

    cout << "delete 3 " << myList->removeBack() << endl;
    cout << "delete 2 " << myList->removeBack() << endl;
    cout << "delete 1 " << myList->removeBack() << endl;

    myList = NULL;
    return 0;
}
