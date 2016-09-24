**题意：给一个矩阵，每一位是0或1，找到只包含1的最大正方形面积。**

**样例：**
```
given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
```

<br/>
**和前天做的google笔试题（要求最多的正方形个数）很像。dp状态：dp[i][j]表示以(i,j)为右下角的最大正方形边长。如果matrix[i][j]=0，则dp[i][j]=0；matrix[i][j]=1时由三个状态转移过来，dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;**

```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxlen = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = matrix[i][0]-'0';
            maxlen = max(maxlen, dp[i][0]);
        }
        for(int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j]-'0';
            maxlen = max(maxlen, dp[0][j]);
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j]-'0') dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        return maxlen * maxlen;
    }
};
```