**题意：有一个数组，它的第i个元素是一支给定的股票在第i天的价格。设计一个算法来找到最大的利润。你最多可以完成两笔交易。你不可以同时参与多笔交易(你必须在再次购买前出售掉之前的股票)。**

<br/>

**这个系列的第一个题目是交易一次，正着遍历就记录到当前位置的最小值，也可以倒着遍历做，记录到当前位置的最大值也就是可以卖出的最大值。**

```
class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> prices) {
        int _max = -1;
        int ans = 0;
        for(int i = prices.size()-1; i >= 0; i--){
            _max = max(_max, prices[i]);
            ans = max(ans, _max - prices[i]);
        }
        return ans;
    }
};
```

**本题是要交易两次，那就开一个数组记录从0到当前位置交易的最大额度。然后倒着遍历，就相当于将数组分成了两段`0~i-1`和`i~n-1`。这样就得到了交易两次的最大利润额。但是题目要求的是最多交易两次，所以就是可以交易一次也可以交易两次。**

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<int> one(n, 0);
        int _min = 0x7fffffff;
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            _min = min(prices[i], _min);
            maxProfit = max(maxProfit, prices[i] - _min);
            one[i] = maxProfit;
        }
        int _max = 0;
        int ans = 0;
        int two = 0;
        for(int i = n-1; i > 0; i--){
            _max = max(prices[i], _max);
            two = max(two, _max - prices[i]);
            ans = max(ans, two + one[i-1]);
        }
        return max(ans, one.back());
    }
};
```
