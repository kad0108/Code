**题意：给n门课，上一些课程是有前提的，比如[0,1]表示上课程0需先上课程1，给定一些课程的前提要求，问是否可以上完所有课程。**

**样例：**
```
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

<br/>
**拓扑排序问题，判断有向图是否有环。**

**解法一：选入度为0的点输出，删除该点及它指向的边，重复上述过程直到不存在入度为0的点，若图中还有剩余顶点未被删除，则说明图中有回路。有环判断：拓扑排序后还有节点的入度不为0，拓扑排序系列长度小于节点个数。**

```
class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& preMap) {
        vector<int> inDeg(n, 0);//记录每个点入度
        for(int i = 0; i < preMap.size(); i++)
        {
            inDeg[preMap[i].second]++;
        }
        stack<int> stk;
        for(int i = 0; i < inDeg.size(); i++)
        {
            if(inDeg[i] == 0) stk.push(i);
        }
        vector<int> ans;
        while(!stk.empty())
        {
            int from = stk.top();
            stk.pop();
            ans.push_back(from);
            for(int i = 0; i < preMap.size(); i++)
            {
                if(preMap[i].first == from) 
                {
                    int to = preMap[i].second;
                    inDeg[to]--;
                    if(inDeg[to] == 0) stk.push(to);
                }
            }
        }
        if(ans.size() < n) return false;//最后输出的点的个数小于总节点数，则图中有环
        return true;
    }
};
```

<br/>
**解法二：dfs，需要标记每个节点是不是被访问过，只要在当前深搜路径上碰到了被访问过的节点，那么就有环。效率没有上一个方法好。**

```
class Solution {
public:
    vector<bool> vis;
    unordered_set<int> path;
    bool hasCircle(int u, vector<pair<int, int>>& preMap)
    {
        if(vis[u]) return false;//不再去访问已经遍历过的路径，比如先搜过0->1->2->5..，又搜0->3->2这时，如果2->...那条路径有环已经在主函数中return，所以这时可以直接返回无环，继续搜其他节点，防止TLE
        vis[u] = true;
        path.insert(u);
        for(int i = 0; i < preMap.size(); i++)
        {
            if(preMap[i].first == u)
            {
                int to = preMap[i].second;
                if(path.find(to) != path.end() || hasCircle(to, preMap))
                {
                    return true;
                }
            }
        }
        path.erase(u);
        return false;
    }
    bool canFinish(int n, vector<pair<int, int>>& preMap) {
        path.clear();
        vis.assign(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && hasCircle(i, preMap)) return false;
        }
        return true;
    }
};
```