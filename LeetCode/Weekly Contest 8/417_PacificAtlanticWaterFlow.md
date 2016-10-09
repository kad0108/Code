**题意：给一个矩阵表示大陆，每个非负元素表示大陆这个单元的高度，大陆的上边和左边连接着太平洋，大陆的右边和下边连接着大西洋，水只可以流向高度<=所在单元的上下左右四个方向，找到所有水同时能流向太平洋和大西洋的坐标。**

**样例：**
```
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
```

<br/>
**遇到这种能不能到达目标点的问题可以反向搜索，分别把连接海洋的两边上的点加入队列，bfs去更新对应海洋的布尔矩阵，然后两个矩阵中都为true点就是能同时流向两个海洋的坐标。**
```
struct Node
{
    int x, y;
    Node(){}
    Node(int xx, int yy): x(xx), y(yy){}
};
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

class Solution {
public:
    int n, m;
    bool bound(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>> &vis, queue<Node> &q)
    {
        while(!q.empty())
        {
            Node now = q.front();
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(bound(nx, ny) && !vis[nx][ny])
                {
                    if(matrix[nx][ny] >= matrix[now.x][now.y])
                    {
                        vis[nx][ny] = true;
                        q.push(Node(nx, ny));
                    }
                }
            }
        }
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        n = matrix.size();
        if(n == 0) return ans;
        m = matrix[0].size();
        
        queue<Node> q;
        
        vector<vector<bool>> p(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) 
        {
            q.push(Node(i, 0));//左边
            p[i][0] = true;
        }
        for(int j = 0; j < m; j++) 
        {
            q.push(Node(0, j));//上边
            p[0][j] = true;
        }
        bfs(matrix, p, q);
        
        while(!q.empty()) q.pop();
        
        vector<vector<bool>> a(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) 
        {
            q.push(Node(i, m-1));//右边
            a[i][m-1] = true;
        }
        for(int j = 0; j < m; j++) 
        {
            q.push(Node(n-1, j));//下边
            a[n-1][j] = true;
        }
        bfs(matrix, a, q);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(p[i][j] && a[i][j]) 
                    ans.push_back(make_pair(i, j));
            }
        }
        return ans;
    }
};
```