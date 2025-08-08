/* 300. Longest Increasing Subsequence
brute force: 
ex:
1 9 2 3 4 5
1 9 is shorter than 1 2 3 4 5
picking the immediate ascending number might not produce the optimal solution.
the only way to find increasing sequence is to try all combinations.
then the only way to optimize it is by caching
at every index, include the number if it is smaller than the rest of the seq
*/

class Solution {
public:
    int lis(vector<int>& nums, int index, vector<int>& lisi){
        if(index == nums.size())
            return 0;

        if(lisi[index] != -1)
            return lisi[index];

        for(int i = index + 1; i < nums.size(); i++){
            if(nums[index] < nums[i]){
                lisi[index] = max(lisi[index] , lis(nums, i, lisi) + 1);
            }
        }

        if(lisi[index] == -1)
            lisi[index] = 0;

        cout << index << " : " << lisi[index]<< endl;
        return lisi[index];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> lisi(nums.size(), -1);

        int res = -1;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, lis(nums, i, lisi) + 1); // + 1 
        }
        return res;
    }
};