#include "GenQueue.h"

int main(int argc, char ** argv){

    GenQueue<char> *myQueue = new GenQueue<char>(10);

    myQueue->insert('R');
    myQueue->insert('e');
    myQueue->insert('n');
    myQueue->insert('e');

    cout << "remove: " << myQueue->remove() << endl;

    while(!myQueue->isEmpty()){
        cout << "loop remove :" << myQueue->remove() << endl;
    }

    cout << "Is QUEUE empty? " << myQueue->isEmpty() << endl;

    delete myQueue;
    return 0;
}
