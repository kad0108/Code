**题意：给一个n*m的矩阵，每次只能向下或向右走，问从左上角走到右下角一共有多少条路径**

<br/>
**TLE解法：dfs探索所有路径**
```
class Solution {
public:
    bool mark[105][105];
    int N, M;
    int cot = 0;
    bool bound(int i, int j)
    {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
    void dfs(int i, int j)
    {
        if(i == N - 1 && j == M - 1)
        {
            cot++;
            return;
        }
        if(bound(i, j + 1) && !mark[i][j + 1])
        {
            mark[i][j + 1] = 1;
            dfs(i, j + 1);
            mark[i][j + 1] = 0;
        }
        if(bound(i + 1, j) && !mark[i + 1][j])
        {
            mark[i + 1][j] = 1;
            dfs(i + 1, j);
            mark[i + 1][j] = 0;
        }
    }
    int uniquePaths(int n, int m) {
        memset(mark, 0, sizeof(mark));
        N = n, M = m;
        cot = 0;
        dfs(0, 0);
        return cot;
    }
};
```
<br/>
**AC解法：dp复杂度O(n^2)，dp[i][j]表示从(0, 0)到达(i, j)的路径数，它可以从两个状态转移过来dp[i][j-1]、dp[i-1][j]，这两个状态走到dp[i][j]只需一步，则状态转移方程为dp[i][j] = dp[i-1][j] + dp[i][j-1]。注意初始化需要初始化i=0一整行和j=0一整列。**
```
class Solution {
public:
    int uniquePaths(int n, int m) {
        int dp[105][105];
        for(int i = 0, j = 0; i < n; i++) dp[i][j] = 1;
        for(int j = 0, i = 0; j < m; j++) dp[i][j] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
```
<br/>
**discuss给出一种优化空间复杂度为O(n)的方法**

As can be seen, the above solution runs in O(n^2) time and costs O(m*n) space. However, you may have observed that each time when we update dp[i][j], we only need dp[i - 1][j] (at the same column) and dp[i][j - 1] (at the left column). So it is enough to maintain two columns (the current column and the left column) instead of maintaining the full m*n matrix. Now the code can be optimized to have O(n) space complexity.
```
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> cur(n, 1);
        for(int j = 1; j < m; j++)
        {
            for(int i = 1; i < n; i++)//一列一列计算cur数组
            {
                //要计算的新的cur[i]，需要同一行前一列的值+同一列上一行的值
                cur[i] = cur[i] + cur[i - 1];
            }
        }
        return cur[n - 1];
    }
};
```
<br/>
###Unique Paths II
**题意：给一个n*m的矩阵，元素1表示障碍不可跨越、0表示空地可走，每次只能向下或向右走，问从左上角走到右下角一共有多少条路径**

<br/>
**dp: dp[i][j]表示从i到j可以走的路径数，很多细节处理**

1. n==0时应该直接返回，不能计算m
2. 如果左上角和右下角本身就是障碍，那结果一定为0，然后就发现dp处理时和上一题不太一样，dp值初始化应该为0，然后处理第一行和第一列(dp状态只能由一个状态转移过来)，再处理其他位置的dp。


```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n - 1][m - 1]) return 0;//这句不加也是对的
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(!obstacleGrid[0][0]) dp[0][0] = 1;
        for(int i = 1, j = 0; i < n; i++)
        {
            if(!obstacleGrid[i][j]) dp[i][j] = dp[i - 1][j];
        }
        for(int j = 1, i = 0; j < m; j++)
        {
            if(!obstacleGrid[i][j]) dp[i][j] = dp[i][j - 1];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(!obstacleGrid[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
```