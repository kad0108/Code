**题意：给一个数组，找出最长连续子段积。**

**样例：**
```
given the array [-2,3,-4],
the contiguous subarray [-2,3,-4] has the largest product = 24.
```

**思想是一个大数>0乘上负数会变小，一个小数<0乘上负数会变大，所以记录前缀数组的最大值和最小值，然后判断每一位是否为负数，如果是负数那么交换最大值最小值。**

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], minp = nums[0];
        int ans = maxp;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0) swap(maxp, minp);
            maxp = max(nums[i], maxp * nums[i]);
            minp = min(nums[i], minp * nums[i]);
            ans = max(ans, maxp);
        }
        return ans;
    }
};
```