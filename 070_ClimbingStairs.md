**题意：有n阶楼梯，每次你跨一层楼梯或者两层楼梯，问爬到n层楼梯一共有多少种不同的走法。**

**注意与第55题Jump Game的区别**

<br/>
**dp[i]表示爬到第i层楼梯的不同种走法，它可以由两个状态转移过来dp[i-1]和dp[i-2]**
```
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```