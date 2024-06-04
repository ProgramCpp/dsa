/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return cost[0];
        //if (n == 2)
        //    return min(cost[0], cost[1]);

        int c_1 = 0;
        int c_2 = 0;
        int Cn = 0;

        for (int i = 2; i <= n; i++)
        {
            Cn = min(c_2 + cost[i - 2], c_1 + cost[i - 1]);
            c_2 = c_1;
            c_1 = Cn;
        }

        return Cn;
    }
};
// @lc code=end
