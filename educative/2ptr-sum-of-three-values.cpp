bool FindSumOfThree(vector<int> nums, int target)
{
   // Replace this placeholder return statement with your code
   sort(nums.begin(), nums.end());
   int len = nums.size();
   for(int i = 0; i <= len - 3; i++) {
      int j = i + 1, k = len -1;
      while(j < k) {
         int diff = target - nums[i] - nums[j] - nums[k];
         if (diff == 0){
            return true;
         }
         if(diff < 0 ){
            k--;
         } else {
            j++;
         }
      }
   }
   return false;
}