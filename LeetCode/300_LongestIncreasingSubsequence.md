**题意：给一个数组，求最长上升子序列的长度**

**样例：**
```
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
```

<br/>
**dp O(n^2)**
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int ans = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int maxn = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j]) maxn = max(maxn, dp[j] + 1);
            }
            dp[i] = maxn;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

<br/>
**O(nlogn) 遍历数组，使用lower_bound每次返回res数组中>=当前数的iterator，如果iterator返回end，说明数组中没有比当前数大的，就push进数组中，否则用当前数替换iterator找到的数。这个做法最后vector中存放的并不是真正的结果，但长度是我们要求的最长上升序列的长度。**
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int>::iterator it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};
```