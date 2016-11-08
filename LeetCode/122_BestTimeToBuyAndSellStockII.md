**题意：给一个数组，第ith元素表示第i天石头的价钱。一次交易是先买一块石头然后卖出去，你可以完成多次交易且交易不重叠，计算出最大收益。**

<br/>
**贪心：我的想法是当今天的价格比明天的低就表示可以购买，今天的价格比明天的高就表示可以卖出。开一个变量标记是否已购买，在可购买的情况中判断是否已购买，如果没有则购买，在可卖出的情况中判断是否已购买，如果已购买则卖出。**
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool buy = false;
        int maxp = 0;
        int last;
        for(int i = 0, len = prices.size(); i < len-1; i++)//输入空数组时prices.size()-1不能表示负数，就变成了超大的数
        {
            if(prices[i] < prices[i+1])
            {
                if(!buy)
                {
                    maxp -= prices[i];
                    buy = true;
                }
                last = i+1;//对于样例[1, 2, 4]，会输出1，所以要特别记录一下价格递增的最后一位
            }
            else
            {
                if(buy) 
                {
                    maxp += prices[i];
                    buy = false;
                }
            }
        }
        if(buy) maxp += prices[last];
        return maxp;
    }
};
```
<br/>
**系列题目：121. Best Time to Buy and Sell Stock**

**只允许交易一次，那么记录到当前位置为止的最小price，不断更新最大收益。**
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int minp = 0x7fffffff;
        for(int i = 0; i < prices.size(); i++)
        {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i] - minp);
        }
        return maxp;
    }
};
```