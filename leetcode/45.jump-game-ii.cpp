/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <vector>

using namespace std;

/*
from starting point, make a maximum jump
move to next position and check if you can jump farther than before
if so, increment the jump count.
if you just jumped or past the last position, increment jumps (the last one)


take one jump(++) of nums[i] = x. check the next x indices from i for the next max jump possible. 
from the next index with max jump possible, repeat.
*/

// @lc code=start
class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int jump(vector<int> &nums)
    {
        int maxJump = 0;
        int nextJump = 0;
        int jumps = 0;


        int n = nums.size() - 1;
        for (int i = 0; maxJump < n; i++)
        {
            maxJump = max(maxJump, i + nums[i]);
            if (i >= nextJump || maxJump >= n)
            {
                jumps++;
                nextJump = maxJump;
            }
        }

        return jumps;
    }
};
// @lc code=end
