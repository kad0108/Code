**题意：给一个数组包含重复的元素，返回所有的子集。结果不能包含重复的子集。**

<br/>
**解法一：直接dfs找到所有子集，然后去重。**

```
class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(v);
            return;
        }
        dfs(nums, i + 1);
        
        v.push_back(nums[i]);
        dfs(nums,i + 1);
        v.pop_back();
    }
    bool ifequal(vector<int> &a, vector<int> &b)
    {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        v.clear();
        ans.clear();
        dfs(nums, 0);
        sort(ans.begin(), ans.end());
        vector<vector<int>> ok;
        ok.push_back(ans[0]);
        for(int i = 1; i < ans.size(); i++)
        {
            if(!ifequal(ans[i - 1], ans[i]))
            {
                ok.push_back(ans[i]);
            }
        }
        return ok;
    }
};
```
<br/>
**解法二：因为找子集的做法就是每个元素要或者不要，既然元素有重复，那么就可以这样处理——每个元素要或者不要，要的话要几次（要的次数就是元素的重复次数）。本来想和40.CombinationSumII 处理类似，先预处理再用dfs，看到discuss有很nice的做法不用dfs。**

下一个子集都是在已有子集基础上生成的，例如```[1,2,2]```，第一个子集必然是空集```[]```，

对已排好序的数组中取第一个元素加入（加入它的重复次数这么多次）已有子集得到子集```[1]```；

取出第二个互异元素依次加入（加入它的重复次数这么多次）之前生成的所有子集中得到子集```[2]```,```[2,2]```,```[1,2]```,```[1,2,2]```。

```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for(int i = 0, len = nums.size(); i < len; )
        {
            int cot = 1;
            for(; cot + i < len;)
            {
                if(nums[cot + i] == nums[i]) cot++;
                else break;
            }
            int size = ans.size();
            for(int k = 0; k < size; k++)
            {
                vector<int> v = ans[k];
                for(int j = 0; j < cot; j++)
                {
                    v.push_back(nums[i]);
                    ans.push_back(v);
                }
            }
            i += cot;
        }
        return ans;
    }
};
```
```