**题意：给一个正数，找到能够由完全平方数组成这个数的最少个数。**

**样例：**
```
given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9
```
<br/>
**参考[discuss](https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics/2)：本来还想着和求combinationSum系列那样，求出int范围内所有完全平方数，每个数可以使用多次，然后求和，但是实现起来有点困难。而且这个题不需要求出所有组合情况，所以肯定不能用dfs（复杂度高），应该就是用dp了。**

**dp[i]表示和为i的完全平方数组合中最少个数的情况，所以状态应该由比i小的dp[i-1*1]、dp[i-2*2]、dp[i-3*3]...等转移过来。**

```
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0x7fffffff);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
```

