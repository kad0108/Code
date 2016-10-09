**题意：给一个非空数组，均为正数元素，看数组是否可以被划分为两个和相同的子集**

**样例：**
```
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
```

<br/>
**01背包问题：dp[i][j]表示前i个数拼出和为j的情况是否存在，转移状态为```dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]```，即前i-1个数就可以拼出j或者前i-1个数可以拼出j-nums[i]。但是开二维dp会TLE。**
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum % 2) return false;

        vector<vector<bool>> dp(n, vector<bool>(sum, 0));
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < sum; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j - nums[i] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][sum/2];
    }
};
```

**简化二维dp，省略第一维，dp[j]依然表示使用前i个物品拼出和为j的情况是否存在，
而dp[i][j]需要从i-1的状态转移过来，所以j要倒着算，这样就不会覆盖i-1算出的结果**
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum % 2) return false;

        vector<int> dp(sum, 0);//vector<bool>没有|操作，而且用bool会TLE，也是好奇怪
        dp[0] = true;
        dp[nums[0]] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = sum; j >= nums[i]; j--)//i-1算出来的结果不能被覆盖，所以要倒着算j
            {
                dp[j] |= dp[j-nums[i]];//这里很奇怪，写成dp[j]||dp[j-nums[i]]就RE
            }
        }
        return dp[sum/2];
    }
};
```

<br/>
**看了discuss，递归写法，思想和dp是一样的**
```
class Solution {
public:
    bool cal(vector<int>& nums, int i, int sum)//前i个数拼成和为sum的情况是否存在
    {
        if(sum == 0) return true;
        if(sum < 0) return false;
        if(i < 0) return false;//如果上两个条件没有return，那么这个条件必须加上
        if(cal(nums, i-1, sum-nums[i])) return true;
        else return cal(nums, i-1, sum);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return false;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum % 2) return false;

        return cal(nums, n-1, sum);
    }
};
```