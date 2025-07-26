/* 53. Maximum subarray
intuition:
keep a running sum. reset when sum goes negative. track maximum sum => O(n)
good intuition. but brute force is to, sum numbers between every pair of indicecs and fix max sum => O(n^2)
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;

        for(int i = 0; i < nums.size(); i++){
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};