**题意：给一个字符串，求最长回文子序列。**

**样例：**

```
Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
```

<br/>

**dp[i][j]表示从i到j这段区间内最长的回文子序列。从dp[i][j-1]、dp[i+1][j]、dp[i+1][j-1]这三个状态转移过来。**

```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int i = n-1; i >= 0; i--){ // 正着遍历时拿不到子状态
            for(int j = i+1; j < n; j++){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2 * (s[i] == s[j]));
            }
        }
        return dp[0][n-1];
    }
};
```
