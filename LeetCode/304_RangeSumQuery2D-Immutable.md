**系列问题：303. Range Sum Query - Immutable**

**题意：给一个数组，返回索引i～j之间的数之和**

**样例：**
```
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```

**感觉这题不是dp啊，就是简单的递推，本来写了求数组的前缀和 and 后缀和，后来发现后缀和好像并不需要**
```
class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            pre.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        int ans = pre[j];
        if(i != 0) ans -= pre[i-1];
        return ans;
    }
};
```

<br/>
**本题题意：给一个矩阵，给出左上角右下角点的坐标，问这个子矩阵中数字之和**

**样例：**
```
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

The above rectangle is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
```

<br/>
**dp[i][j]表示以(i,j)为右下角的矩阵中数字之和，状态转移方程```dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j]```**
```
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        dp.assign(n, vector<int>(m, 0));
        dp[0][0] = matrix[0][0];
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        for(int j = 1; j < m; j++)
        {
            dp[0][j] = dp[0][j-1] + matrix[0][j];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp.size() == 0) return 0;
        int ans = dp[row2][col2];
        if(col1 != 0) ans -= dp[row2][col1-1];
        if(row1 != 0) ans -= dp[row1-1][col2];
        if(col1 != 0 && row1 != 0) ans += dp[row1-1][col1-1];
        return ans;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
```