**题意：给一个数组和一个target，找出所有求和为target的不重复的组合，每个元素只能使用一次**

**样例：**
```
input: [10, 1, 2, 7, 6, 1, 5] and target 8
output: [
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**解法一：dfs找出所有组合后暴力去重**

```
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    vector<int> v;
    int target;

    bool judge(vector<int> &a, vector<int> &b)
    {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    void dfs(int i, int sum)
    {
        if(i == nums.size())
        {
            if(sum == target)
            {
                if(ans.size() > 0)
                {
                    bool flag = true;
                    for(int j = 0; j < ans.size(); j++)
                    {
                        if(judge(ans[j], v)) return;
                    }
                }
                ans.push_back(v);
            }
            return;
        }
        dfs(i + 1, sum);
        if(sum + nums[i] > target) return;
        v.push_back(nums[i]);
        dfs(i + 1, sum + nums[i]);
        v.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int t)
    {
        sort(candidates.begin(), candidates.end());
        nums = candidates;
        target = t;
        ans.clear();
        v.clear();
        dfs(0, 0);
        return ans;
    }
};
```
<br/>
**解法二：对比39题，上一题是元素无限制使用，本题理解为元素使用次数是其重复次数，对输入数组预处理得到每个元素重复个数，用struct存储**
```
class Solution {
public:
    struct Node
    {
        int val;
        int cot;
    };
    vector<vector<int>> ans;
    vector<Node> nums;
    vector<int> v;
    int target;

    void pre(vector<int> &c)
    {
        int cot = 1;
        for(int i = 0, len = c.size(); i < len; i++)
        {
            if(i > 0 && c[i] == c[i - 1]) cot++;
            else if(i > 0 && c[i] != c[i - 1])
            {
                nums.push_back(Node{c[i - 1], cot});
                cot = 1;
            }
            if(i == len - 1) nums.push_back(Node{c[i], cot});
        }
    }
    void dfs(int i, int sum)
    {
        if(i == nums.size())
        {
            if(sum == target)
            {
                ans.push_back(v);
            }
            return;
        }
        dfs(i + 1, sum);
        int j;
        for(j = 1; ; j++)
        {
            int temp = nums[i].val * j;
            if(sum + temp > target || j > nums[i].cot)//这里注意j>cot时也需要--操作
            {
                j--;
                break;
            }
            v.push_back(nums[i].val);
            dfs(i + 1, sum + temp);
        }
        while(j--)
        {
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t)
    {
        target = t;
        sort(c.begin(), c.end());
        pre(c);
        target = t;
        dfs(0, 0);
        return ans;
    }
};
```