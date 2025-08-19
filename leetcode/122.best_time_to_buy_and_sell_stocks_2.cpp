/* 122. Best Time to Buy and Sell Stock II
intuition:
track buy price and sum profits whenever you sell.
when a stock is available at lower price, sell and buy.
track maxProfit until the day you sell.
wrong.
you have to clock maxProfit and buy again to make more profit.
hint: 1 4 7. buy@1 and sell@7 gives a profit 6 = buy@1, sell@4 + buy@4, sell@7
"you can sell and buy on the same day". buying is beneficial but selling at a lower price is lossy. so sell earlier and buy at the lowest price.
so you dont wait for a lesser buy price to find the profit. you find price lesser than the previous sell price at max profit.
imagine the whole pattern is a series of rises and falls.
i.e, keep selling at higher prices. keep updating buy price in the downward trend.
you can sell at an immediate higher price and dont have to wait for max profit because of the above hint.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int buyPrice  = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > buyPrice){ // keep adding until prices keep increasing
                totalProfit += prices[i] - buyPrice;
                buyPrice = prices[i];
            } else if(prices[i] < buyPrice) { // do not sell when the price is falling
                buyPrice = prices[i];
            }
        }

        return totalProfit;
    }
};

// intuition
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int totalProfit = 0;
//         int maxProfit = 0;
//         int buyPrice  = prices[0];

//         for(int i = 0; i < prices.size(); i++){
//             maxProfit= max(maxProfit, prices[i] - buyPrice);
//             if(prices[i] < buyPrice){
//                 totalProfit += maxProfit;
//                 buyPrice = prices[i];
//                 maxProfit = 0;
//             }
//         }

//         totalProfit += maxProfit;

//         return totalProfit;
//     }
// };