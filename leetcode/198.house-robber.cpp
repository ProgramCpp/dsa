/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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
        int maxTheft = 0;

        for (int i = 3; i <= n; i++)
        {
            maxTheft = max(nums[i - 1] + t_2, t_1);
            t_2 = t_1;
            t_1 = maxTheft;
        }

        return maxTheft;
    }
};
// @lc code=end
