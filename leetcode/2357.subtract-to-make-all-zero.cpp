// 2357.  Make Array Zero by Subtracting Equal Amounts


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int i = 0; i < nums.size(); count++){
            // handle repeated numbers.
            // do it first - to clean leading 0's
            // handle array out of bounds
            while(i < nums.size() && !nums[i])
                i++;

            // cleaning 0's might have processed the inp array
            if(i == nums.size())
                return count;
            
            int x = nums[i];
            for(int j = i; j < nums.size(); j++)
                nums[j] = nums[j] - x;

        }
        return count;
    }
};
