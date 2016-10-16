**题意：给一个矩阵包含X和O，把所有被X包围的O修改为X**

**样例：**
```
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
```

<br/>
**可以看出边缘处的O和与其相连的O都不会被X包围，所以先处理四个边，之后剩余的O就是被X包围的。**

**用dfs写大数据总是RE，应该是暴栈了，递归调用了三万多层，然后就用bfs写AC了。**
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
    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<Node> q;
        board[i][j] = 'F';
        q.push(Node(i, j));
        while(!q.empty())
        {
            Node now = q.front();
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(bound(nx, ny) && board[nx][ny] == 'O')
                {
                    board[nx][ny] = 'F';
                    q.push(Node(nx, ny));
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) return;
        m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][m-1] == 'O') bfs(board, i, m-1);
        }
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O') bfs(board, 0, j);
            if(board[n-1][j] == 'O') bfs(board, n-1, j);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'F') board[i][j] = 'O';
            }
        }
        return;
    }
};
```