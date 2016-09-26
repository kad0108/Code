**题意：给一个矩阵，其中每个元素表示所在位置的高度，计算在下过雨之后总共能蓄多少水。**

**样例：**
```
Given the following 3x6 height map:(Before the rain)
[
  [3, 5, 5],
  [5, 4, 5],
  [5, 5, 5]
]

After the rain, water are trapped between the blocks. The total volume of water trapped is 1:
[
  [3, 5, 5],
  [5, 5, 5],
  [5, 5, 5]
]
```

<br/>
**从矩阵的最外层往里灌水，能围住的水取决于高度最低的边界，用优先队列，首先将矩阵外层加入优先队列并标记，从最小的高度x向四周走到nextx，如果没出边界且没被访问过，看nextx高度如果比x高度低，那么水会流入nextx，更新nextx高度加入优先队列并标记。可以发现整个过程中优先队列中的元素在矩阵中都是向里围起来的。**

```
struct Node
{
    int x, y, h;
    Node(){}
    Node(int xx, int yy, int hh): x(xx), y(yy), h(hh){}
    bool operator < (const Node &o) const
    {
        return h > o.h;//小顶堆
    }
};
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

class Solution {
public:
    bool bound(int x, int y, int r, int c)
    {
        return x >= 0 && x < r && y >= 0 && y < c;
    }
    int trapRainWater(vector< vector<int> >& map) {
        int r = map.size();
        if(r == 0) return 0;
        int c = map[0].size();
        priority_queue<Node> pq;
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        int ans = 0;

        for(int i = 0; i < r; i++)
        {
            vis[i][0] = 1;
            pq.push(Node(i, 0, map[i][0]));
            vis[i][c-1] = 1;
            pq.push(Node(i, c-1, map[i][c-1]));
        }
        for(int j = 0; j < c; j++)
        {
            vis[0][j] = 1;
            pq.push(Node(0, j, map[0][j]));
            vis[r-1][j] = 1;
            pq.push(Node(r-1, j, map[r-1][j]));
        }
        while(!pq.empty())
        {
            Node now = pq.top();
            pq.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(bound(nx, ny, r, c) && !vis[nx][ny])
                {
                    ans += max(now.h - map[nx][ny], 0);
                    pq.push(Node(nx, ny, max(now.h, map[nx][ny])));
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};
```

**注意：**

1. priority_queue默认维护的是大顶堆以及less(<)，对于Node类型的优先队列，需要在struct内部重载小于号，这样优先队列才会比较两个Node类型。
2. 重载小于号，返回a<b是大顶堆，返回a>b是小顶堆。也可以定义```priority_queue<int, vector<int>, greater<int>> pq```然后重载大于号来实现。
3. 向周围走时高度会比原来位置高，水不会流入，ans += 0。