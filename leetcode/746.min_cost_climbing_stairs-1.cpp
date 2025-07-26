/* 746. Min Cost Climbing Stairs
intuition:
each step can be reached from its previous two steps.
min cost to a step is min cost of previous two steps (not including itself. its cost is included only in next jumps).
Note, reach top floor. u start from stairs and reach top FLOOR
=> O(n)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // jumping from previous 2 stairs, its cost included
        vector<int> minCost(n, 0);

        if(n == 1)    
            return cost[0];

        minCost[0] = cost[0];
        // min of the two stairs is computed in return statement
        // top floor is reached from either 1st stair or second stair. when reaching from 2nd stair, its cost is incured
        minCost[1] = cost[1]; // reach stair 2. stepping on the stair incurs its cost

        for(int i = 2; i< n; i++){
            minCost[i] = min(minCost[i-1], minCost[i-2]) + cost[i] ; // stepping on the stair incurs its cost
        }

        return min(minCost[n-1], minCost[n-2] ) ; // the top floor doesnt incur cost
    }
};