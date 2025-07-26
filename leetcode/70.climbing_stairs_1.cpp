/*70. Climbing Stairs
intuition: every step can be reached from previous two steps. 
similarly, nth step can be reached from previous 2 steps. find number of ways to reach steps n -1 and n-2. add them
=> O(n)
note: u are on the floor, all `n` stairs are in front of you.
space complexity can be reduced from O(n) to O(1) by storing only the previous 2 values required for computation
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> noOfWays(n, 0);

        // handle 1 stairs. below code only works for n >= 2
        if(n == 1) 
            return 1;

        noOfWays[0] = 1; // 1 stair (n - 1 = 0)
        noOfWays[1] = 2; // 2 stairs (n -1  = 1)

        for(int i = 2; i < n; i++){
            noOfWays[i] = noOfWays[i-1] + noOfWays[i-2];
        }

        return noOfWays[n-1]; // indexed from 0
    }
};