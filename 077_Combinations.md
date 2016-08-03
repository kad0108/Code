**题意：给出n和k，返回由1~n的元素组合成大小为k的序列。**

**和 Combination Sum III 题意很相似**

**样例：**
```
input：n=4, k=2
output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

**暴力dfs：这种做法实际上扩展了很多无用节点。思想是这个元素要不要。**

```
class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    int N, K;
    bool mark[1005];
    void dfs(int i)
    {
        if(v.size() == K)
        {
            ans.push_back(v);
            return;
        }
        if(i > N) return;//这个判断一定放在上一个判断之后，不然最后一个元素一直都进不来
        dfs(i + 1);
        v.push_back(i);
        dfs(i + 1);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        v.clear();
        ans.clear();
        memset(mark, 0, sizeof(mark));
        dfs(1);
        return ans;
    }
};
```
<br/>
**优化dfs：从输出样例可以知道每次都向当前元素的后方匹配，不会出现类似(2, 1)这样的结果序列。所以，每次扩展序列中的元素，只需要从上一个加入序列的元素索引的下一位begin开始扩展即可。**
```
class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    int N, K;
    void dfs(int begin)
    {
        if(v.size() == K)
        {
            ans.push_back(v);
            return;
        }
        for(int i = begin; i <= N; i++)
        {
            v.push_back(i);
            dfs(i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        v.clear();
        ans.clear();
        dfs(1);
        return ans;
    }
};
```