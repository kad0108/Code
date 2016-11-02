**题意：数组中每个元素表示最多能走的步数，初始位置为0，问你到达数组末尾最少需要走几步。**

**样例：**
```
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
```

<br/>
**TLE解：bfs，找所有的路径到达n-1就更新最少步数**
```
struct Node
{
    int index;
    int step;
};
class Solution {
public:
    int min_step;
    vector<bool> vis;
    void bfs(vector<int>& nums)
    {
        queue<Node> q;
        vis.assign(nums.size(), 0);
        q.push(Node{0, 0});
        vis[0] = 1;
        while(!q.empty())
        {
            Node now = q.front();
            if(now.index == nums.size()-1) 
            {
                min_step = min(min_step, now.step);
            }
            q.pop();
            int l = now.index - nums[now.index], r = now.index + nums[now.index];
            for(int i = now.index + 1; i < nums.size() && i <= r; i++)
            {
                if(!vis[i])
                {
                    q.push(Node{i, now.step+1});
                    vis[i] = 1;
                }
            }
            if(now.index != 0)
            {
                for(int i = now.index - 1; i >= l && i >= 0; i--)
                {
                    if(!vis[i])
                    {
                        q.push(Node{i, now.step+1});
                        vis[i] = 1;
                    }
                }
            }
        }
        
    }
    int jump(vector<int>& nums) {
        min_step = 0x7fffffff;
        bfs(nums);
        return min_step;
    }
};
```

<br/>
**AC解： dp[i]表示到达i的最小步数，对于每一个i所能到达的这些位置的dp可以由dp[i]+1转移过来。**
```
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int cur_max = 1;
        for(int i = 0; i < n; i++)
        {
            for(; cur_max <= i + nums[i] && cur_max < n; cur_max++)
            {
                dp[cur_max] = dp[i] + 1;
            }
        }
        return dp[n-1];
    }
};
```

<br/>
**系列问题：55. Jump Game**

**题意：给你一个非负数组，初始位置为0，数组每个元素表示你最多能走几步，问你是否能到达数组末尾**

**样例：**
```
A = [2,3,1,1,4], return true
A = [3,2,1,0,4], return false
```
<br/>
**TLE解法： bfs,是去找所有可以走的路径看能不能到达n-1**
```
class Solution {
public:
    int n;
    vector<int> mark;
    bool bfs(vector<int>& nums)
    {
        queue<int> q;
        mark.assign(n, 0);
        q.push(0);
        mark[0] = 1;
        while(!q.empty())
        {
            int now = q.front();
            if(now == n - 1) return true;
            q.pop();
            int l = now + nums[now], r = now - nums[now];
            for(int i = now + 1; i <= l && i < n; i++)
            {
                if(!mark[i])
                {
                    q.push(i);
                    mark[i] = 1;
                }
            }
            if(now != 0)
            {
                for(int j = now - 1; j >= 0 && j >= r; j--)
                {
                    if(!mark[j])
                    {
                        q.push(j);
                        mark[j] = 1;
                    }
                }
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        n =  nums.size();
        return bfs(nums);
    }
};
```
<br/>
**AC：递推思想O(n)，找到最远能到达的位置maxreach，那么比这个近的位置都能到达了**
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        int n = nums.size();
        for(int i = 0; i < n && i <= maxreach; i++)//i最远能走maxreach所以需要加第二个限制条件
        {
            maxreach = max(maxreach, i + nums[i]);
        }
        return maxreach >= n - 1;
    }
};
```