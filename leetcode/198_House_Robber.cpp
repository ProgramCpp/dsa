// 198. House Robber

/*
start at 0 and 1. keep adding alternate values. return max!
=> O(n)

doesnt work. skip 2 consecutive houses to make more money

for every ith position, track the maximum amount that can be robbed so far, which is equal to the max amount if the ith house is robbed or not
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxAmount;
        
        if (nums.size() == 1)
            return nums[0];

        maxAmount.push_back(nums[0]);
        maxAmount.push_back(max(nums[0], nums[1]));

        for(int i = 2; i < nums.size(); i++){
            maxAmount.push_back(max(maxAmount[i-1], maxAmount[i-2] + nums[i]));
        }

        return maxAmount[nums.size() - 1];
    }
};