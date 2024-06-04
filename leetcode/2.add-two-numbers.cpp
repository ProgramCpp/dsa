/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

using namespace std;
// @lc code=start
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result, *l3;
        result = new ListNode();
        l3 = result;
        while (l1 != nullptr || l2 != nullptr)
        {
            int r = 0;
            if (l1 != nullptr)
                r += l1->val;

            if (l2 != nullptr)
                r += l2->val;

            r = r + l3->val;
            l3->val = r % 10;

            if (r > 9)
                l3->next = new ListNode(1);
            else (l1->next != nullptr || l2->next != nullptr)
                l3->next = new ListNode();

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
            l3 = l3->next;
        }

        return result;
    }
};
// @lc code=end
