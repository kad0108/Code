/**
* 假设有一个数组，它的第i个元素是一个给定的股票在第i天的价格。设计一个算法来找到最大的利润。
* 你可以完成尽可能多的交易(多次买卖股票)。然而,你不能同时参与多个交易(你必须在再次购买前出售股票)。
*/

class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> prices) {
        if(prices.size() == 0) return 0;
        bool buy = false;
        int sum = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] < prices[i+1] &&!buy){
                sum -= prices[i];
                buy = true;
            }else if(prices[i] > prices[i+1] && buy){
                sum += prices[i];
                buy = false;
            }
        }
        if(buy) sum += prices.back();
        return sum;
    }
};
