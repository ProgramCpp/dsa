/* 322. coin change
intuition: try every combination of denominations of coins and find the combination with the least number of coins. 
trying bigger denomination first leads to fewer coins
is it? is there a counter example? i.e, starting with a bigger denomination leads to more coins
ex: 5, 4, 1. amount is 8. 
5 + remaining 3 = 1 * 3. total coins = 4 (5 * 1coin + 1 * 3coins). but optimal solution is, 2. (4 *2coins)
use one coin denomination and repeat for the remaining amount. repeat for every other denomination.
note: the optimal number of coins for an amount is the same. cache the results for recomputation
*/

class Solution {
public:
    int change(vector<int>& coins, int amount, map<int, int> &amounts){
        if(amount == 0)
            return 0;

        if(amount < 0)
            return -1;

        if(amounts[amount])
            return amounts[amount];
        
        int minCoins = INT_MAX;
        for(auto i : coins){
            int x  = change(coins, amount - i, amounts);
            if (x != -1)
                    minCoins = min(minCoins, x + 1);
        }

        if(minCoins == INT_MAX)
            minCoins = -1;

        amounts[amount] = minCoins;

        return minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        map<int, int> amounts;

        return change(coins, amount, amounts);
    }
};