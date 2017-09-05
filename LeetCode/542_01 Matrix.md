**题意：给一个只包含0和1的矩阵，找出每个单元格到0最近的距离。相邻两个格子之间距离为1。**

**样例：**
```
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
```

<br/>

**TLE解：遍历矩阵，在每个点上做bfs。**

```
class Solution {
public:
    struct Node{
        int val;
        int cot;
        int x;
        int y;
        Node(int val, int cot, int x, int y): val(val), cot(cot), x(x), y(y) {};
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int n = matrix.size();
        if(!n) return vector<vector<int>>();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                queue<Node> q;
                vector<vector<int>> flag(n, vector<int>(m, 0));
                q.push(Node(matrix[i][j], 0, i, j));
                flag[i][j] = 1;
                while(!q.empty()){
                    Node now = q.front();
                    q.pop();
                    if(now.val == 0) {
                        ans[i][j] = now.cot;
                        break;
                    }
                    for(int k = 0; k < 4; k++){
                        int nx = now.x + dx[k], ny = now.y + dy[k];
                        if(bound(nx, ny, n, m) && !flag[nx][ny]){
                            q.push(Node(matrix[nx][ny], now.cot+1, nx, ny));
                            flag[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    bool bound(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};
```

<br/>

**AC解：不应该从非0点开始走，应该从0点开始bfs，遇到下一步的值大于当前值则更新。**

```
class Solution {
public:
    struct Node{
        int x, y;
        Node(int x, int y): x(x), y(y){};
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return vector<vector<int>>();
        int m = matrix[0].size();
        queue<Node> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0) q.push(Node(i, j));
                else matrix[i][j] = 0x7fffffff;
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            Node now = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = now.x + dx[k], ny = now.y + dy[k];
                if(bound(nx, ny, n, m) && matrix[nx][ny] > matrix[now.x][now.y]){
                    q.push(Node(nx, ny));
                    matrix[nx][ny] = matrix[now.x][now.y] + 1;
                }
            }
        }
        return matrix;
    }
private:
    bool bound(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};
```
