/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        int t_2 = nums[0];
        int t_1 = max(nums[0], nums[1]);
        int firstMaxTheft = t_1;


        for (int i = 3; i <= n - 1; i++)
        {
            firstMaxTheft = max(nums[i - 1] + t_2, t_1);
            t_2 = t_1;
            t_1 = firstMaxTheft;
        }

        t_2 = nums[1];
        t_1 = max(nums[1], nums[2]);
        int lastMaxTheft = t_1;

        for (int i = 4; i <= n; i++)
        {
            lastMaxTheft = max(nums[i - 1] + t_2, t_1);
            t_2 = t_1;
            t_1 = lastMaxTheft;
        }

        return max(firstMaxTheft, lastMaxTheft);
    }
};
// @lc code=end
