// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> input;

        for (int i = 0 ; i < nums.size(); i++){
            input[nums[i]] = i;
        }
        for (int i = 0 ; i < nums.size(); i++){
            std::unordered_map<int, int>::iterator it = input.find(target - nums[i]);
            if (it != input.end() && i != it->second)
            {
                return std::vector<int>({i, it->second});
            }
        }

        return vector<int>();
    }
};
// @lc code=end


// 1. two sum

// Q's:
// is the input sorted?
// can the same number repeated give the target?
// can the index be returned in any order?
// is index counted from 0?
// can the numbers be negative?
// can the numbers repeat?

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complements;

        for(int i = 0; i < nums.size(); i++){ 
            if (complements.find(nums[i]) != complements.end()) {
                // note syntax for initializing a static vector
                return vector<int>({i, complements[nums[i]]});
            }   
            // first check presence before initializing. 
            // otherwise, when sum of number with itself gives target. the same index is returned
            complements[target - nums[i]] = i;
        }
        return vector<int>();
    }
};
