// 918. Maximum Sum Circular Subarray

/*
brute force : O(n^3)
kadane's algorithm : O(n)

suggested solution: max(maxSum, total - minSum)
suggested solution: max(maxSum, prefixMaxSum + suffixMaxSum)

use i = 1 % n
track the start of sub array. terminate on overlap -  just an optimization. KISS
if 0 is encountered, check if its already encountered -  just an optimization. KISS

doesnt work: say, the whole array is included in the max subarray. 
but excluding certain numbers in the centre might produce bigger sum. suggested solution is the ONLY WAY
ex: [5, -3, 5]
*/


// SOLUTION COPIED!!!


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            curMax = max(curMax, 0) + nums[i];
            maxSum = max(maxSum, curMax);
            curMin = min(curMin, 0) + nums[i];
            minSum = min(minSum, curMin);
        }

        if (total == minSum) {
            return maxSum;
        }
        
        return max(maxSum, total - minSum);
    }
};