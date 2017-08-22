**题意：给一个n*n的矩阵，每行每列递增，找到第k小的数(1 < k < n^2)**

<br/>

**样例：**

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
```

**AC解一： O(n^2logk)**

```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(pq.size() == k && pq.top() > matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
                if(pq.size() < k) pq.push(matrix[i][j]);
            }
        }
        return pq.top();
    }
};
```

<br/>

**AC解二：O(klogn) 先把每行第一个数入优先队列，然后每次pop最小的值，并push这个数所在行的下一列的值，这样pop k-1次优先队列中剩余的就是第k小的数。**

```
struct Node{
    int val;
    int i;
    int j;
    Node(int val, int i, int j): val(val), i(i), j(j) {};
    bool operator < (const Node &o) const{
        return val > o.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            pq.push(Node(matrix[i][0], i, 0));
        }
        while(--k){
            Node now = pq.top();
            pq.pop();
            if(now.j < n-1) pq.push(Node(matrix[now.i][now.j+1], now.i, now.j+1));
        }
        return pq.top().val;
    }
};
```
