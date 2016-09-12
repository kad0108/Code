**题意：给一个数组，求出每一位除本位值外其他所有位值的乘积。**

**记录前缀积pre[]和后缀积post[]，那么结果就是pre[i-1]*post[i+1]**
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 1) return vector<int>(1, 1);
        vector<int> pre(nums.size(), 1);//前缀积
        vector<int> post(nums.size(), 1);//后缀积
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0) pre[i] = nums[i];
            else pre[i] = pre[i-1] * nums[i];
        }
        for(int i = nums.size()-1; i>= 0; i--)
        {
            if(i == nums.size()-1) post[i] = nums[i];
            else post[i] = post[i+1] * nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0) nums[i] = post[i+1];
            else if(i == nums.size()-1) nums[i] = pre[i-1];
            else nums[i] = pre[i-1] * post[i+1];
        }
        return nums;
    }
};
```
<br/>
**用O(n) space complexity 实现。pre数组保留，求post时，开一个变量记录，同时计算post，同时计算结果。**