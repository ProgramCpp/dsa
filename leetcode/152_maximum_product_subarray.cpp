// 152. Maximum Product Subarray
/*

brute force => n^3
keep track of product from ith position => n^2

keep track of both max product and min product
=> O(n)

product of even +ve or -ve nums gives max product
exclude until first -ve or after last -ve
0 reduces the product. reset.
=> keep track of maxProd. start from begining once. start from end once. reset on 0
*/

class Solution {
public:
    int max (int a , int b){
        if (a > b)
            return a;
        else
            return b;
    }

    int min (int a , int b){
        if( a < b)
            return a;
        else
            return b;
    }

    int maxProduct(vector<int>& nums) {
        // handle when 0 is the max product
        // do not init max and min prod to 1. start with first element
        int maxProd = nums[0];
        int minProd = nums[0];

        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            // if i is 0, still find max. ex: [-2, 0] 0 is the max product
            // if(nums[i] == 0){
            //     if(i + 1 == nums.size())
            //         break;
            //     i++;
            //     maxProd = max(0, nums[i]);
            //     minProd = min(0, nums[i]);
            // } else{
                int t = maxProd;
                maxProd = max(max(maxProd * nums[i], minProd * nums[i]), nums[i]);
                minProd = min(min(t * nums[i], minProd * nums[i]), nums[i]);
            // }
            if(res < maxProd)
                res = maxProd;
        }

        return res;
    }
};