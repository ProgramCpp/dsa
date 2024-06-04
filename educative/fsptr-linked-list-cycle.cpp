#include "LinkedList.cpp"

bool DetectCycle(EduLinkedListNode* head){
  EduLinkedListNode *slow = head, *fast = head-> next;
  // Replace this placeholder return statement with your code
  while (fast != NULL){
    if (slow == fast) 
      return true;
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  
  return false;
}