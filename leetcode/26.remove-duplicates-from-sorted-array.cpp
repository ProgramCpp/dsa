/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0;
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[ptr]){
                ptr++;
                nums[ptr] = nums[i];
            }
        }
        return ptr + 1;
    }
};
// @lc code=end

