**题意：给一个数组，返回是否存在上升子序列长度为3的情况**

**样例：**
```
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
```

<br/>
**用dp求最长上升子序列，然后返回maxLen>=3，直接TLE了**

<br/>
**O(n) 定义上升子序列长度为3的第一个数为candidate1，第二个数为candidate2，初始化为INT_MAX，遍历数组，如果当前数<=candidate1，就更新candidate1，如果>candidate1，则看是否<=candidate2，更新candidate2，如果>candidate2，则存在长度为3的上升序列。**
```
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int candidate1 = 0x7fffffff, candidate2 = 0x7fffffff;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= candidate1) candidate1 = nums[i];
            else if(nums[i] <= candidate2) candidate2 = nums[i];
            else return true;
        }
        return false;
    }
};
```