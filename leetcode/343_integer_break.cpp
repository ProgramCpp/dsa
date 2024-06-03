// 343. Integer Break

/*
Hint 1
For all x, y >1, product(x,y) ≥ sum(x,y)

Hint 2
It follows that it always makes sense to try to split the sum into the most components > 1 possible, as product > sum

Hint 3
2 and 3 sum up to any number ≥ 2*, so it always makes sense to break it down into 2s and 3s. The optimal answer will be comprised of only 2s and 3s
*(you can trivially prove this because 1 and 2 sum up to every number, and 3 is 2+1)

Hint 4
do not break down to 1. 1 does not increase the product


solution:
get max products of sub problems because larger products will give even larger result for n.
sub problems: max of n = 2 + (n - 2 ) and n = 3 + (n -3)

OR

https://youtu.be/TMfaNbjy1pI?si=BWEFiS1cmxDF5kU_
divide n into 2 parts, combinatorially
iteratively sub divide the 2 parts until it is either 2 or 3
*/

class Solution {
public:

    int integerBreakAndStore(int n, vector<int> & store){
        int max = 0;

        if(store[n] != -1)
            return store[n];

        // not storing. not a problem
        if(n == 1)
            return 1;

        // handling 2 and 3 again and again!
        // when input is 2 or 3, the product is less than 2 and 3.
        // but when computing product, dont divide 2 and 3 further. it will lead to 1, reducing the product
        if(n == 2)
            return 2;

        if ( n == 3) 
            return 3;

        for(int i = 2; i < n; i++){
            int val = integerBreakAndStore(i, store) * integerBreakAndStore(n - i, store);
            if(max < val)
                max = val;
        }

        store[n] = max;
        return max;
    }
    int integerBreak(int n) {
        if(n == 2)
            return 1;

        if ( n == 3) 
            return 2;

        vector<int> store(n + 1, -1);
        return integerBreakAndStore(n, store);
    }
};