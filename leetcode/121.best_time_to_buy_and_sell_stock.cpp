/* 121. Best Time to Buy and Sell Stock
u must buy at lowest price and sell at highest price to make max profit.
intuition: start parsing the array. keep track of the price to buy and the price to sell.
update the prices, if u find a lower price to buy or higher price to sell. 
what if lowest buy price is found after the highest sell price?
track only buy price. for every sell price, find max profit so far.   
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = prices[0];

        for(int i = 1; i < prices.size(); i++){
            buyPrice = min(buyPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyPrice); // -ves are handled by max too
        }

        return maxProfit;
    }
};