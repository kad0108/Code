**题意：给一个n*m的矩阵，每次只能向下或向右走，问从左上角走到右下角的路径上数字最小和**

<br/>
**TLE解法：dfs是一条路走到头，所以可以得到每条路径的数字之和，每探索一步就更新增加sum，直到到达右下角则更新minSum，回溯时则更新减少sum。**
```
class Solution {
public:
    int n, m;
    bool mark[1005][1005];
    int minSum, sum;
    vector<vector<int>> grid;
    bool bound(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i, int j)
    {
        if(i == n - 1 && j == m - 1)
        {
            minSum = min(minSum, sum);
            return;
        }
        if(bound(i + 1, j) && !mark[i + 1][j])
        {
            mark[i + 1][j] = 1;
            sum += grid[i + 1][j];
            dfs(i + 1, j);
            sum -= grid[i + 1][j];
            mark[i + 1][j] = 0;
        }
        if(bound(i, j + 1) && !mark[i][j + 1])
        {
            mark[i][j + 1] = 1;
            sum += grid[i][j + 1];
            dfs(i, j + 1);
            sum -= grid[i][j + 1];
            mark[i][j + 1] = 0;
        }
    }
    int minPathSum(vector<vector<int>>& nums) {
        grid = nums;
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        memset(mark, 0, sizeof(mark));
        minSum = 0x7fffffff;
        sum = grid[0][0];
        dfs(0, 0);
        return minSum;
    }
};
```
**注意：**

在类中定义一个数组int a[1005][1005],在main函数中定义Solution so时，相当于把数组开在了main函数内，而int比bool大小大4倍，改为bool a[1005][1005]就不会RE。
一般函数内不要开超过10^4的int，大数组都开到函数外边。

<br/>
**AC解法：dp[i][j]表示从(0, 0)到(i, j)的路径，这条路径上的数字和最小**
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        for(int i = 1, j = 0; i < n; i++) grid[i][j] += grid[i - 1][j];
        for(int j = 1, i = 0; j < m; j++) grid[i][j] += grid[i][j - 1];
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};
```
