/* 377. Combination Sum IV
intuition: from 416, subtract ith value from target and repeat for every i until target becomes 0.
=> O(n^n) // for each i, the remaining value can be subtracted by n values again
cache every possible target to avoid recomputation
=> O(n * t)
*/

class Solution {
public:

    int cs(vector<int>& nums, int target, vector<int>& noofways){
        if(target == 0)
            return 1;

        if(noofways[target] != -1)
            return noofways[target];

        int ways = 0;
        for(auto i : nums){
            if(target >= i){
                ways += cs(nums, target - i, noofways);
            }
        }

        noofways[target] = ways;

        return ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> noofways(target + 1, -1); // -1. cache 0 ways to compute as well
        return cs(nums, target, noofways);
    }
};