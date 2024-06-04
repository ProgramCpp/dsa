#include "LinkedList.cpp"	
#include "LinkedListReverse.cpp"

 
bool Palindrome(EduLinkedListNode* head){
  EduLinkedListNode *slow = head, *fast= head;
  while(fast != NULL) {
    slow = slow -> next;
    fast = fast -> next;
    if (fast != NULL)
      fast = fast-> next;
  }

  EduLinkedListNode *half = ReversedList(slow);

  while(half != NULL) {
      if (half -> data != head-> data)
        return false;

      half = half -> next;
      head = head -> next;
  }
  
  return true;
}