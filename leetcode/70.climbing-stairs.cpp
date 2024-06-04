/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int n_1 = 2;
        int n_2 = 1;

        int Cn = 0;
        if (n == 1)
            return n_2;
        if (n == 2)
            return n_1;

        for(int i = 3; i <= n; i++){
            Cn = n_2  + n_1 ;
            n_2 = n_1;
            n_1 = Cn;
        }

        return Cn;
    }
};
// @lc code=end
