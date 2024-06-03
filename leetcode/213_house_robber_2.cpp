// 213. House robber 2

/*
Hint: Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes, to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.
*/

class Solution {
public:
    // start to end has atleast 2 elements
    int rob(vector<int> &nums, int start, int end){
        // make sure maxAmount has same size as nums. start and end are indices of nums
        vector<int> maxAmount(nums.size());
        maxAmount[start] = nums[start];
        maxAmount[start + 1] =  max(nums[start], nums[start+1]);

        for(int i = start + 2; i <= end; i++){
            maxAmount[i] = max(maxAmount[i-1], maxAmount[i-2] + nums[i]);
        }

        return maxAmount[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
};