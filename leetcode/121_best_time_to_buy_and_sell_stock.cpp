// 121. Best Time to Buy and Sell Stock

/*
start with buying on first day and track max profit by selling at other days.
if the price is lesser on some other day, update the buying day to the lowest price day. continue calculating profit for subsequent days
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = 0;
        for(int i = 1; i < prices.size();i ++){
            if(prices[i] > prices[buy]){
                if(maxProfit < prices[i] - prices[buy])
                    maxProfit = prices[ i] - prices[buy];
            } else{
                buy = i;
            }
        }
        return maxProfit;
    }
};