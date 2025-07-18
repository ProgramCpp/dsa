/*75. Sort Colors

approach 1: count different colored balls. fill the number of boxes with respective colors. O(2n)
can you optimize 2n -> n?
O(3n). parse whole array and place red color balls first in 1st iteration, then white and then blue. do multiple colors at once?
start filling red from beginning and blue from end. O(n)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for (int i =0, j = n-1, k = 0 ; k <= j;){
            if(nums[k] == 0){ // swap red to its place
                int x = nums[i];
                nums[i] = nums[k];
                nums[k] = x;
                i++;
                if (k < i)
                    k = i; // k must be atleast i. everything left of i is already sorted
            }else if(nums[k] == 2){ // swap blue to its place
                int x = nums[j];
                nums[j] = nums[k];
                nums[k] = x;
                j--;
            } else
                k++; // leave blue 
        }
    }
};