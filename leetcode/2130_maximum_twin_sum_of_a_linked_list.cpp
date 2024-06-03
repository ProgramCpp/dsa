// 2130. Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
// max of list[i] + list[n -i] - reverse list and find max of sums upto half the length of list
// to reverse linked list, need 2 pointers, cur and prev
// Qs:
// is this a doubly linked List
/*Hint: use stack to iterate from back*/

/** * Definition for singly-linked list. **
struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){} *
};*/
class Solution
{
public:
    int length(ListNode *head)
    {
        int n = 0;
        while (head)
        {
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head)
            return NULL;

        if (!head->next)
            return new ListNode(head->val);

        // copy and then in-place reverse? can do it together?

        ListNode *prev = new ListNode(head->val);
        ListNode *cur = head->next;

        while (cur)
        {
            ListNode *tmp = new ListNode(cur->val, prev);
            // tmp->next = prev;
            prev = tmp;
            cur = cur->next;
        }
        return prev;
    }

    void print(ListNode *l)
    {
        while (l)
        {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }

    int pairSum(ListNode *head)
    {
        ListNode *rev = reverse(head);

        int n = length(head);
        int max = 0;
        if (!head)
            return max;

        print(head);
        print(rev);
        for (int i = 0; i < n / 2; i++)
        {
            if (head->val + rev->val > max)
                max = head->val + rev->val;
            head = head->next;
            rev = rev->next;
        }
        return max;
    }
};