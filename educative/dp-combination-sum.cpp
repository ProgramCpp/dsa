vector<vector<int>> CombinationSum(vector<int>& nums, int target) 
{
    vector<vector<vector<vector<int>>>> sums(nums.size()+1, vector<vector<vector<int>>>(target + 1, vector<vector<int>>(0)));

    // for(int i = 0; i <= target; i++)
    //     sums[0][i] = {{}};

    // for(int i = 0; i <= nums.size(); i++)
    //     sums[i][0] = {{}};

    for(int i = 1; i <= nums.size(); i++){
        for (int j = 1; j <= target; j++){
            sums[i][j] = sums[i-1][j];
            // when i = 0 is used for base case, i-1 will index the input array. use i-1 for all nums index
            // handle base case
            if(j-nums[i-1]==0)
                sums[i][j].push_back({nums[i-1]}); // push a vector. not just a int
            
            if(j-nums[i-1] >= 0){
                for (vector<int> v : sums[i][j-nums[i-1]]){
                    v.push_back(nums[i-1]);
                    sums[i][j].push_back(v);
                }
                    
            }//else{
                // for (vector<int> v : sums[i-1][j])
                //     sums[i][j].push_back(v);
                
            //}
            
        }
    }

    return sums[nums.size()][target];
}
