**题意：给一个矩阵，1表示陆地，0表示水，一个小岛是连成在一起的1被0围着，问总共有多少个岛。**

**样例：**
```
11000
11000
00100
00011
Answer: 3
```

<br/>
**每次从没被标记的1出发，把遇到的相邻的1都标记，遇到0返回，每个点最多被标记一次，所以复杂度为O(n^2)。可以再开一个标记数组，也可以直接修改1为其它值。**
```
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
class Solution {
public:
    int n, m;
    bool bound(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(grid[i][j] != '1') return;
        grid[i][j] = '9';
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(bound(x, y) && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        int cot = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1') 
                {
                    dfs(grid, i, j);
                    cot++;
                }
            }
        }
        return cot;
    }
};
```