/* 279. Perfect Squares
intuition: the numbers that make up n must be perfect squares. and least number of squares that make up n.
start from n, n-1... 1. check if ith value is a perfect square and repeatedly solve for n - ni until 0.
then repeat starting from every i value again, since n may not be formed by some ith number.
ex: 12.
12, 11, 10 are not perfect squares. 9 is a perfect square. 12 - 9 = 3, not a perfect square. does not add upto n.
next perfect square is 4. 12 - 4 = 8. biggest perfect square less than 8 is again 4. 8-4 = 4. 4-4 = 0.
to summarize. list perfect squares less than or equal to n. ex: 12: 9, 4, 1.
try to find sum of some of these numbers so that the sum is n. recall coin change/ combination sum.
cache results for every i, since same i would be solved again and again when the sum is started from different squares
*/
class Solution {
public:
    int sumSq(vector<int> &nums, int n, vector<int> &leastSq){
        if(n == 0)
            return 0;

        if(leastSq[n] != -1)
            return leastSq[n];

        int sq = -1; // sum of none of nums sum to n
        // order is imp to get least number of squares
        for(auto i : nums){
            if(i <= n){
                int sum = sumSq(nums, n - i, leastSq);
                if(sum != -1 && (sq == -1 || sq > sum + 1)) // todo: once sum is found, no need to continue, since the later numbers are always smaller and lead to bigger number of squares.
                    sq = sum + 1;
            }
        }

        leastSq[n] = sq;

        return sq;
    }

    int numSquares(int n) {
        // perfect squares <= n
        vector<int> nums; // to avoid checking every integer every time

        for(int i = n; i >= 1; i--){
            int x = sqrt(i);
            if(x * x == i)
                nums.push_back(i);
        }

        vector<int> leastSq(n + 1, -1);
        return sumSq(nums, n, leastSq);
    }
};