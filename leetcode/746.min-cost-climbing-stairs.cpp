/*
746. min cost climbing stairs

calc min cost to reach stair i = min(cost[i] + minCost[i-1], cost[i] + minCost[i-2])
where stairs start from 0
note, when landing on a step, you incur cost from that step. and you can land on a step from the previous stair or the one before that one.
now you have calculated the cost to reach the end of the array/ stairs.

NOTE: the problem asks for cost past the stairs. thus the result is min of last 2 values, since it can be reached from either stairs.

NOTE: the cost to reach the second stair is the cost[2]. when you are landing on 2nd stair, you are incuring its cost. no need to consider jump from the first stair. do note, when the array size is 2, it does work, but does not scale beyond.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         /*
        std::vector performs bounds checking when the at() member function is used, but it does not perform any checks with operator[].When out of bounds operator[] produces undefined results.
        */
        vector<int> minCost;

        if (cost.size() == 0)
            return 0;


        /*
        if (cost.size() > 0) // > 0. add in both cases of size 1 and 2
            minCost.push_back(cost[0]);

        if (cost.size() > 1)
            minCost.push_back(min(cost[0],cost[1]));
        
        for (int i = 2; i < cost.size() ; i++){
            minCost.push_back(min(cost[i] + minCost[i - 1], cost[i]+ minCost[i-2]));
        }

        int n = minCost.size();
        return minCost[n];

        */

         if (cost.size() > 0) // > 0. add in both cases of size 1 and 2
            minCost.push_back(cost[0]);

        if (cost.size() > 1)
            minCost.push_back(cost[1]);
        
        for (int i = 2; i < cost.size() ; i++){
            minCost.push_back(min(cost[i]+ minCost[i - 1], cost[i]+ minCost[i-2]));
        }

        int n = minCost.size();
        return min(minCost[n-1], minCost[n-2]);
    }
};

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
