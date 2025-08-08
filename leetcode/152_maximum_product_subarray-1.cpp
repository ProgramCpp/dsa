/* 152. maximum product subarray
intuition: for every sub array size, compute the product and find max product.
=> O(n^2). for every index, multiply with every other num
cache the results of subarrays. how do you correlate the already solved sub problems?
solve sub arrays of length 2 and then 3 etc
=> O(n^2)
[i][j], gives max prod from ith index to jth index
problem: say the max product [5][10] is excluding the last number -10. but max product [5][11], where 11th number is -20. you cannot use the pre computed max product [5][10]. i.e, the first -ve will be excluded, but the next number will make it +ve
alternatively, 
what reduces the product?
a single negative number or zero
reset product to 1 when nums have 0.
before resetting, the current product must be trimmed either until the first negative number or after the last negative number, to track the max prodt.
=> O(n)
NOTE: ALL ELEMENTS MUST BE CONTIGUOUS
ex: -2, -1, -3 & -1, -2, -3
calc 
max = max(cur max * n, cur min * n, n)
min = min(cur max * n, cur min * n, n)
return cur max.
do you know why it works? 
it fixes the problem with -ve numbers.
a negative value reduces the product. the first -ve number makes the min product and the next -ve num makes it a max prod. that and the max product gives the overall max prod
definitely not intuitive!
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0]; // when one num is present, that is the max prod, not INT_MIN
        int maxProd = nums[0]; // 1 is max compared to negative values in nums
        int minProd = nums[0];

        for(int i = 1 ; i < nums.size(); i++){
            // if (nums[i] == 0 && i + 1 < nums.size()){
            //     res = max(res, maxProd);
            //     minProd = nums[i+1];
            //     maxProd = nums[i+1];
            //     i++;
            // } else if (nums[i] == 0){
            //     res = max(res, maxProd);
            //     continue;
            // }
            // doesnt 0 make the product 0? maxProd and minProd wont be updated in that case
            // if max product continues to update with product before 0, doesnt it exclude element 0 from the product, making it non-contiguous?
             // res is computed at every max prod computation, that's key.
             // once 0 is reached, it is part of min prod  or max prod depending on +ve or -ve computed prod 
             // eventually, it is overwritten by actual max or min prod, essentially resetting the prod
            int x = maxProd;
            maxProd = max({nums[i], nums[i] * maxProd, nums[i] * minProd});
            minProd = min({nums[i], nums[i] * x, nums[i] * minProd});
            res = max(res, maxProd);
        }

        return res;
    }
};