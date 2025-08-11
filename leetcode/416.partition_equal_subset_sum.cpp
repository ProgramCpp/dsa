/* 416. Partition Equal Subset Sum
intuition:
sum of some set of elements(a) and the sum of *rest* of the elements(b) must match.
to find a, find all combinations of elements.
or
for every index i, include that element in the first set or the second set. repeat for the nums after the index (the ones before are already included)
=> O(2 ^ n)
the sub array gets repeatedly solved, which can be cached
but what is the relation from Sn to Sn+1
Hint: the sum = total sum / 2
all you have to do is find if any combination of nums produce the sum, meaning the remaining nums also produce the sum (total sum / 2)
thus, when i = 0, and sum, solve for i =1, sum = sum0 - nums[0] || sum
cache result from index to sum
=> O(N * S), N, numsl S, sum. max sum = 100 * 200/ 2 = 10000. n * s = 2000000  // for every new sum, you solve for that index again
space complexity can be futher reduced. there is no need to cache results. terminate as soon as theres a succesful match and short circuit - doesnt work because at every index, the algorithm branches, when returning back the call stack, some of the calculations are redone in other branches, especially when the branch doesnt produce the result (0 cached result).
*/

class Solution {
public:
    bool partitionSum(vector<int>& nums, int index, int sum, vector<vector<int>> &sums){
        // cout << index << ": " << sum << endl;
        if(index == nums.size())
            return false;
        
        if(nums[index] == sum){// sum == 0 condition is redundant
            sums[index][sum] = 1;
            return true;
        }

        if (sums[index][sum] != -1){ // -1, not computed; 0 evaluated to false; 1, evaluated to true
            return sums[index][sum];
        }

        // bool a = false, b = false;
        // if(nums[index] < sum){
        //     a = partitionSum(nums, index + 1, sum - nums[index], sums);
        //     cout << index << " : included with sum " << sum << " " << a << endl;
        // }

        // b = partitionSum(nums, index + 1, sum, sums);
        // cout << index << " : not included with sum " << sum << " " << a << endl;

        // todo: do not compute this case if the earlier case already found the sum

        bool res = nums[index] < sum ? (partitionSum(nums, index + 1, sum - nums[index], sums) || partitionSum(nums, index + 1, sum, sums)) : partitionSum(nums, index + 1, sum, sums); // **short-circuit**

        // cout << index << " : " << sum << " : " << res << endl;
        if (res){
            sums[index][sum] = 1;
        } else 
            sums[index][sum] = 0;

        return  res;
    }

    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        int sum = 0;
        for(auto i : nums){
            totalsum += i;
        }

        if(totalsum % 2)
            return false;

        sum = totalsum /2;

        vector<vector<int>> sums(nums.size(), vector<int>(sum + 1, -1));
        return partitionSum(nums, 0, sum, sums);
    }
};