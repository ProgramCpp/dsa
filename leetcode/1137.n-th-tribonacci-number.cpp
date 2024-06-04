/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
#include <iostream>

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        int n_3 = 0;
        int n_2 = 1;
        int n_1 = 1;
        int Tn = 0;
        for (int i = 3; i <= n; i++)
        {
            Tn = n_1 + n_2 + n_3;
            n_3 = n_2;
            n_2 = n_1;
            n_1 = Tn;
        }
        return Tn;
    }
};

// @lc code=end

int main()
{
    Solution s;

    std::cout << s.tribonacci(25);
    return 0;
}