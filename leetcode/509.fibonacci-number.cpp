// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem509.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int fibNMinus2 = 0;
        int fibNMinus1 = 1;
        int fibX = 0;
        for (int fibI = 2; fibI <= n; fibI++)
        {
            fibX = fibNMinus1 + fibNMinus2;
            fibNMinus2 = fibNMinus1;
            fibNMinus1 = fibX;
        }
        return fibX;
    }
};
// @lc code=end
