#include "LinkedList.cpp"	

// The code in "LinkedList.cpp" can be used to create a linked list out of a list. 
// The code in "LinkedListTraversal.cpp" can be used to traverse the linked list.
// The code in "LinkedListReversal.cpp" can be used to reverse the linked list.

EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){
  EduLinkedListNode *slow = head, *fast = head-> next;
  // Replace this placeholder return statement with your code
  while(fast != NULL){
    slow = slow-> next;
    fast = fast -> next;
    if(fast) 
      fast = fast -> next;
  }
  return slow;
}