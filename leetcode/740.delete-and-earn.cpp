/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution
{
public:
    int Max(int a, int b)
    {
        return a > b ? a : b;
    }

    bool isPrevLessThan(map<int, int>::iterator it)
    {
        return it->first == (--it)->first + 1;
    }

    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        map<int, int> f;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            f[*it] += *it; 
        }

        int n_1Max = 0, n_2Max = 0, max = 0;

        for (map<int, int>::iterator it = f.begin(); it != f.end(); it++)
        {
            max = f.begin() != it && isPrevLessThan(it) ? Max(max, n_2Max + it->second) : Max(max, n_1Max + it->second);
            n_2Max = n_1Max;
            n_1Max = max;
        }

        return max;
    }
};
// @lc code=end
