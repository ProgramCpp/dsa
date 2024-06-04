/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        for (; i < j;)
        {
            if (!((s[i] >= 48 && s[i] < 58) ||
                  (s[i] >= 65 && s[i] < 91) ||
                  (s[i] >= 97 && s[i] < 123)))
            {
                i++;
                continue;
            }
            if (!((s[j] >= 48 && s[j] < 58) ||
                  (s[j] >= 65 && s[j] < 91) ||
                  (s[j] >= 97 && s[j] < 123)))
            {
                j--;
                continue;
            }
            if (s[i] >= 97)
                s[i] = s[i] - 32;
            if (s[j] >= 97)
                s[j] = s[j] - 32;
            if (s[i] != s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
// @lc code=end
