#include "ListNode.h"

ListNode::ListNode(){
    data = 0;
    prev = NULL;
    next = NULL;
}

ListNode::ListNode(int d){
    data = d;
    prev = NULL;
    next = NULL;
}

ListNode::~ListNode(){
    prev = NULL;
    next = NULL;
}
