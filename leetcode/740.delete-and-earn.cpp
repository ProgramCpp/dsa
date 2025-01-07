/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

/*
740. delete and earn

if you take one number, you can take them all - deduplicate the values, but keep track of individual sums and order the nums. 
if you take one number, you cannot take adjacent numbers. ring a bell? house robbery!

at any position i, if you take i, you cannot take i - 1 and i + 1. the profit at i is max(vi + vi-2, vi-1). note that taking/ not taking Vi impacts only surrounding values. it doesnt have a ripple effect. this calls for DP.

what if you skip 2 consecutive values? i and i + 1. are you taking i + 2 then? then you might as well take i isnt it? so not a valid concern


Hint 1
If you take a number, you might as well take them all. Keep track of what the value is of the subset of the input with maximum M when you either take or don't take M.

*/

// writing the iterative code - feeling a bit adventurous. solution is TLE but passes 23 Tc's. 
// can use dp instead. max points = maxn. where maxi = max(vi + vi-2, vi-1)
// note, at any i, you only need maxi-1 and maxi-2. dont need to store max at every i. further reducing the space complexity from O(n) to O(1)
class Solution {
public:

    // check if the previous element in the map is consecutive
    // ex: if i->first is 5, returns true if i-1 -> first is 4 
    bool isPrevLessThan(map<int, int>::iterator it)
    {
        return it->first == (--it)->first + 1;
    }

    int Points(map<int, int> &nums, map<int, int>::iterator i){
        if (i == nums.begin()) {
            cout << i -> first << ":" << i -> second << "i = 0" << endl ;
            return i->second;
        }

        // handling first two places so that all n-2 indices falls within the range
        if (i == ++nums.begin()) { // only ++ and -- operators are supported
            if (isPrevLessThan(i)) { // if consecutive, pick the max of the two elements. else, take both
                cout << i -> first << ":" << max(i-> second, nums.begin()-> second)<< "i = 1" << endl;
                return max(i-> second, nums.begin()-> second);
            }
            else{
                cout << i -> first << ":" << i -> second + nums.begin() -> second << "i = 1'"<< endl;
                return i -> second + nums.begin() -> second;
            }
        }

        map<int, int>::iterator i_ = i; // do not alter i
        map<int, int>::iterator i_1 = --i_;
        map<int, int>::iterator i_2 = --i_;

        
        if (isPrevLessThan(i)) {
            int s = max(Points(nums, i_1), Points(nums, i_2) + i -> second);
            cout << i -> first << ": " << s << endl;
            return max(Points(nums, i_1), Points(nums, i_2) + i -> second);
        } else {
            // add all points of prev number since they are not consecutive
            int max = Points(nums, i_1) + i -> second;
            // if (isPrevLessThan(i_1)) {
            //     max += 
            // }
            cout << i -> first << ":" << max << "i'"<< endl;
            return max;
        }
        
    }

    int deleteAndEarn(vector<int>& nums) {
        // orderd map to access adjacent elements
        // note: map iterator is bidirectional. so iterator arithmatic is O(r) where r is the constant operand
        // in this use case, only surrounding members are accessed. thus O(1)
        // note: order of elements in map matter. if n is taken, n-1 and n+1 cannot be taken
        // note when the nums are ordered, the adjacent nums in the map are not always consecutive.

        /*
        std::map<T>::iterator is of the iterator-class bidirectional iterator. Those only have ++ and -- operators. 
        +N and [] is only available for random access iterators (which can be found in e.g. std::vector<T>).
        */

        // HINT: what if you find the maxinum number in the input. create an array of that size and just access element by the input numbers?
        map<int, int> orderedNums;

        for (int x : nums){
            if (orderedNums.find(x) == orderedNums.end())
                orderedNums[x] = 0;
            orderedNums[x] += x;
        }

        return Points(orderedNums, --orderedNums.end());
    }
};

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