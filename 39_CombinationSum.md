**题意： 给一个set数组和一个target，找出所有不重复的求和为target的情况，同一个元素可以使用多次。**

**样例：**
```
input： set [2, 3, 6, 7] and target 7
output：solution set is [ [7], [2, 2, 3] ]
``` 
<br/>
**解：DFS求解，考虑每一位元素要或者不要，要的话再考虑要几次。**
```
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    vector<int> v;
    int target;
    void dfs(int i, int sum)//i：数组索引，sum：当前v中元素求和
    {
        if(i == nums.size())
        {
            if(sum == target)
            {
                ans.push_back(v);
//                v.clear();//因为后面要这一位的时候pop过了，所以这儿不能clear
            }
            return;
        }
        dfs(i + 1, sum);
        int cot = 0;
        for(cot = 1; ; ++cot)
        {
            int temp = cot * nums[i];
            if(sum + temp > target)
            {
                cot--;
                break;
            }
            v.push_back(nums[i]);
            dfs(i + 1, sum + temp);
        }
        while(cot--)
        {
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int t)
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