// 53. Maximum Subarray

/*
for every length of sub array, compute the sum
=> n^3

for every length of sub array, compute the sum. keep track of sum so far, starting at ith index
=> n^2

TLE on TC 204

keep adding 1 number at a time. keep track of max num. once sum is negative, reset sum : kadanes algorithm

=> n

*/

class Solution {
public:
    int maxNum(int a, int b){
        if(a > b)
            return a;
        else 
            return b;
    }
    int maxSubArray(vector<int>& nums) {
        // handle negative numbers
        int max = INT_MIN;

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = maxNum(nums[i], sum + nums[i]); // if a number makes sum 0. start with that num if +ve instead of 0
            if(sum > max)
                max = sum;
        }

        return max;
    }
};