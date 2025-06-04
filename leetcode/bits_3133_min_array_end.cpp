/*
3133. Minimum Array End
intuition: each number in nums AND x must be x. brute force numbers AND with x.
remember, nums should have the least possible values.
any bit after MSB of x is a valid num. 
for a bit of x, corresponding bit of num must be,
1 & 1 = 1
0 & 1 = 0
0 & 0 = 0
num cannot be 0, if x is 1.
start from LSB, to maintain increasing order

start with x, for each bit from LSB, add to nums based on the above table
wrong, when processing every bit position, modify every 0 bit from LSB
and u only need n-1th element? 

SS: https://leetcode.com/problems/minimum-array-end/editorial
you almost came up with 2 of the suggested solutions!

*/

class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long result = x;
        // i serves 2 purposes, to count nums and to track incrementing nims[i]
        // nope. i doesnt increment always
        for (int i = 0; i < n - 1  ; i++) {
            // why result + 1? see editorial!
            result = x | (result+1);
        }

        return result;
    }
};

/*
- the above alogirithm yields duplicates
*/
/*
        ni: 3, x: 1(001)        ni | x                nums
        1                        1 | 1 = 1            1
        2                       10 | 1 = 11           3
        3                       11 | 1 = 11           3
since 3 is dupe, compute again?
        4                      100 | 1 = 101          5

no need to remember all the previous values. only consecutive numbers give same num
*/