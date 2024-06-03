
// 2055. Plates Between Candles

// https:
// leetcode.com/problems/plates-between-candles/description/

// precompute leftmost and right most candle positions. and prefix sum of candles
// prefix sum for range based queries

// https:
// leetcode.com/problems/plates-between-candles/solutions/1586720/intuition-explained-prefix-sum-and-binary-search-c-clean-code
class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        // default value of vector is 0
        int n = s.length();
        // not leftmost and right most - isnt useful
        // compute previous and next candle index for the given index
        vector<int> leftmostCandle(n), rightmostCandle(n), prefixSum(n);
        for (int i = 0; i < n; i++)
        {
            leftmostCandle[i] = s[i] == '|' ? i : (i == 0 ? -1 : leftmostCandle[i - 1]);
            rightmostCandle[n - 1 - i] = s[n - 1 - i] == '|' ? n - 1 - i : (n - 1 - i == n - 1 ? -1 : rightmostCandle[n - 1 - i + 1]);
            prefixSum[i] = s[i] == '*' ? (i == 0 ? 1 : prefixSum[i - 1] + 1) : (i == 0 ? 0 : prefixSum[i - 1]);
        }

        // for (auto i: leftmostCandle)
        // cout << i << ' ';
        // cout << endl;

        // for (auto i: rightmostCandle)
        // cout << i << ' ';
        // cout << endl;

        // for (auto i: prefixSum)
        // cout << i << ' ';
        // cout << endl;
        vector<int> response;
        for (int i = 0; i < queries.size(); i++)
        {
            int iLeftmostCandle = leftmostCandle[queries[i][1]];
            int iRightmostCandle = rightmostCandle[queries[i][0]];
            if (iLeftmostCandle == -1 || iRightmostCandle == -1)
                response.push_back(0);
            // else if(iRightmostCandle > iLeftmostCandle){
            // response.push_back(0);
            // } // not possible!
            else if (iLeftmostCandle < queries[i][0] || iRightmostCandle > queries[i][1])
            {
                // handle case of no candles in the range
                response.push_back(0);
            }
            else
            {
                // cout << "query " << i+1 << "." << iRightmostCandle << "," << iLeftmostCandle;
                // cout << "." << prefixSum[iLeftmostCandle] << "," << prefixSum[iRightmostCandle] << endl;
                response.push_back(prefixSum[iLeftmostCandle] - prefixSum[iRightmostCandle]);
            }
        }
        return response;
    }
};