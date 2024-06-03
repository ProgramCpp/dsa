// 70. Climbing Stairs

/* NO OF WAYS. not NO OF JUMPS
no of ways: try conbinatorial recursion
no of ways to reach 1 step.
no of ways to reach 2 steps.
total ways = no of ways to reach n-1th step + no of ways to reach n-2th step
use dp to avoid recalculation
*/

class Solution {
public:
    int climbStairsWithPrecomputaiton(int n, vector<int> &stairs){
        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

        if(n == 2)
            return 2;

        if(stairs[n -1] != -1)
            return stairs[n - 1];

        stairs[n -1] = climbStairsWithPrecomputaiton(n-1, stairs) + 
            climbStairsWithPrecomputaiton(n-2, stairs);

        return stairs[n -1 ];
    }

    int climbStairs(int n) {
        vector<int> stairs(n, -1);
        return climbStairsWithPrecomputaiton(n, stairs);
    }
};