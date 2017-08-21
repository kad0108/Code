/**
* 假设有一个数组，它的第i个元素是一支给定的股票在第i天的价格。如果你最多只允许完成一次交易(例如,一次买卖股票),设计一个算法来找出最大利润。
*/

class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> prices) {
        int _min = 0x7fffffff;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            _min = min(_min, prices[i]);
            ans = max(ans, prices[i] - _min);
        }
        return ans;
    }
};
