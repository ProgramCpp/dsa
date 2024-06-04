int FindCoinChange(vector<int>& coins, int total)
{
    // let the initial value be total + 1. INT_MAX + 1 is actually lesser that INT_MAX
    vector<int> minCoins(total + 1, total + 1); 
    minCoins[0] = 0;
    for (int i = 1; i <=total; i++){
        for (int j = 0; j < coins.size(); j++){
            if (i-coins[j] >= 0)
                minCoins[i] = min(minCoins[i], 1 + minCoins[i-coins[j]]);
        }
    }

    return minCoins[total] == total + 1 ? -1 : minCoins[total];
}