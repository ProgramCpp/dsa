#include <iostream>
#include <string>
#include <vector>

EduLinkedListNode *RemoveNthLastNode(EduLinkedListNode *head, int n)
{
    // Replace this placeholder return statement with your code
    EduLinkedListNode *first = head, *last= head;
    for (int  i =0 ; i < n; i++) {
        if (last == NULL) {
            return head;
        }
        last = last -> next;
    }

    if(last == NULL){
        head = head -> next;
    }

    while(last != NULL && last->next != NULL) {
        first = first -> next;
        last = last -> next;
    }

    first -> next = first ->next->next;

    return head;
}