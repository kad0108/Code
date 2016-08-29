**题意：给一个元素互异的数组和一个target，找出所有求和为target的组合，元素不限制使用次数**

**样例：**
```
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
```

**TLE解法：dfs内两层for循环，第一层for循环遍历数组元素，第二层for循环看当前元素要几次，这里有一个小trick，第二层for循环执行的条件是，当前元素不是上一次压入vector v中的元素，不然会出现每次压入vector v中的都会是nums中的第一个元素**

```
class Solution {
public:
    vector<int> v;
    int cot;
    int target;
    vector<int> nums;
    bool mark[1005];
    void dfs(int index, int sum)//index记录上一个加入数组v的数在原数组中的索引
    {
        if(sum == target)
        {
            cot++;
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != index)
            {
                int j;
                for(j = 1; ;j++)
                {
                    int temp = nums[i] * j;
                    if(sum + temp > target)
                    {
                        j--;
                        break;
                    }
                    v.push_back(nums[i]);
                    dfs(i, sum + temp);
                }
                while(j--)
                {
                    v.pop_back();
                }
            }
        }
    }
    int combinationSum4(vector<int>& nu, int t) {
        nums = nu;
        cot = 0;
        target = t;
        memset(mark, 0, sizeof(mark));
        dfs(-1, 0);
        return cot;
    }
};
```
<br/>
**AC解法：dp，参考discuss，dp[i]表示和为i的组合个数。先对nums排序，对于nums数组中的元素e，如果e>i，那么e之后的元素一定不会组合得到i，那么直接计算dp[i+1]；如果e==i，那么当前元素就是一个组合，dp[i]+1；如果e<i，则状态可以由dp[i-e]转移过来。**
```
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] > i) break;
                else if(nums[j] == i) dp[i] += 1;
                else dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
```
<br/>
**Follow up: 考虑如果数组有负数，如何解决？**