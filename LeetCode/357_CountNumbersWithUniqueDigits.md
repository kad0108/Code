**题意：给一个正数n， 返0 <= x < 10^n范围内每位互异的数的个数。**

**样例：**
```
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
```
<br/>
**DFS解法：遇到的bug，对于n=3时，数字010、001是合法的，但是因为先选择了0，导致这样的数字不会被计入。所以应该先枚举数字的长度，这样来控制不让开头出现0。**
```
class Solution {
public:
    vector<bool> digit;
    int cot;
    void dfs(int i, int n)
    {
        if(i == n)
        {
            cot++;
            return;
        }
        for(int j = 0; j < 10; j++)
        {
            if(i == 0 && j == 0) continue;
            if(!digit[j]) 
            {
                digit[j] = 1;
                dfs(i + 1, n);
                digit[j] = 0;
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        digit.assign(10, 0);
        cot = 1;//单独记录数字0
        for(int nn = 1; nn <= n; nn++)
        {
            dfs(0, nn);
        }
        return cot;
    }
};
```
<br/>
**DP解法：因为每一位只有0~9这十个数字可以取，而且最高位不能取0，那么dp[i]表示长度为i的每一位互异的数字个数。**

dp[1] = 10;

dp[2] = 9 * 9; 最高位不能取0则有9种取法，下一位不能取和前一位相同的数字有9种取法

dp[3] = 9 * 9 * 8;

...

dp[10] = 9 * 9 * 8 * 7 * ... * 1; (n <= 10)

当n > 10时，dp[n] = 0

单独处理n = 0的情况。
```
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 10;
        for(int i = 2, val = 9; i <= n; i++, val--)
        {
            if(i == 2) dp[i] = 9 * 9;
            else dp[i] = dp[i-1] * val;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};
```
