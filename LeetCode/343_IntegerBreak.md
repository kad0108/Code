**题意：给一个正数n，把它分割成不少于两个数之和，求出这其中乘积最大的一组。**

**样例：**
```
given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
```

<br/>
**dp解：题目给出提示，从7~10的分割情况中总结规律。**
```
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for(int i = 5; i <= n; i++)
        {
            for(int j = 2; j + j <= i; j++)
            {
                dp[i] = max(max(j, dp[j]) * max(i-j, dp[i-j]), dp[i]);
            }
        }
        return dp[n];
    }
};
```