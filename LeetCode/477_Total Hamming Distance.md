**系列题目：461. Hamming Distance**

**题意：定义Hamming Distance为两个数的二进制表示同一位不相同的个数。现在给一个数组，计算数组中每两个数的distance之和。数组长度为10^4，明显两层for会TLE**

<br/>
**我们只关心同一位有多少个(1,0)组合，n个数字，某一位有k个数在这一位是1，则有n-k个数在这一位是0，那么这一位的(1,0)组合就有k*(n-k)个**
```
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; ++i)
        {
            int bitone = 0;
            for(int j = 0; j < n; ++j)
            {
                if((nums[j] >> i) & 1) bitone++;
            }
            ans += bitone * (n - bitone);
        }
        return ans;
    }
};
```