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