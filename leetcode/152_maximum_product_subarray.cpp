// 152. Maximum Product Subarray
/*

brute force => n^3
keep track of product from ith position => n^2

keep track of both max product and min product
=> O(n)

possible integers: +ve, -ve and 0
product of even +ve or -ve nums gives max product
exclude until first -ve or after last -ve. the first occurance of -ve might flip the max prod or the last occurance of -ve

The idea is based on the fact that overall maximum product is maximum of following two: 

    Maximum product in left to right traversal.
    Maximum product in right to left traversal

=> keep track of maxProd. start from begining once. start from end once. reset on 0
0 reduces the product. reset.
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
                maxProd = max(max(maxProd * nums[i], minProd * nums[i]), nums[i]); // if current product is 0. initialize it with num at i
                minProd = min(min(t * nums[i], minProd * nums[i]), nums[i]); // if current product is 0. initialize it with num at i
            // }
            if(res < maxProd)
                res = maxProd;
        }

        return res;
    }


// WIP
    int maxProduct(vector<int>& nums) {
        // handle when 0 is the max product
        // do not init max and min prod to 1. start with first element
        int maxProdFront = 0;
        int maxProdBack = 0;

        int curProdFront = nums[0];
        int curProdBack = nums[nums.size()-1];
        for(int i = 1; i < nums.size(); i++){
            int prod = curProdFront == 0? nums[i] : curProdFront * nums[i]; // if current product is 0. initialize it with num at i
            if (prod > maxProdFront)
                maxProdFront = prod;

            int prod = curProdBack == 0? nums[i] : curProdBack * nums[i]; // if current product is 0. initialize it with num at i
            if (prod > maxProdBack)
                maxProdBack = prod;
        }

        return maxProdFront > maxProdBack ? maxProdFront : maxProdBack;
    }
};