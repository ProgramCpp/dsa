// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        for (int i = nums.size() - 1; i > 0;)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] >= i - j)
                {
                    i = j;
                    continue;
                }
            }
            if (i != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> inp = {2, 3, 1, 1, 4};
    s.canJump(inp);
}