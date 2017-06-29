**题意： 给一个数据，其中每个数都满足`1 ≤ a[i] ≤ n (n = size of array)`, 有些数出现了两次，有些没出现，找出所有`[1,n]`中没出现的，O(n)时间、O(1)空间实现**

<br/>

**样例：**

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

<br/>

**解法一： 首先想到OfferCode里面的解法，从左到右遍历数组，把i位置上的数字都交换回这个数字应该在的位置，直到i位置上放了正确的数字i+1。这个题就是一直交换直到要交换到的位置上也放了正确的数字，这样就说明有重复的数字出现了。遍历一遍之后再遍历一遍看哪个位置上数字不对应，就说明缺少了这个数字。for+while看最终时间复杂度，看均摊每个元素被访问了几次，每个元素最终最多会被交换两次就一定会回到正确的位置上，所以总体上复杂度是O(2n)**

```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        if(!len) return vector<int>();
        for(int i = 0; i < len; i++){
            while(nums[i]-1 != i){
                if(nums[nums[i]-1] == nums[i]) break;
                swap(nums[i], nums[nums[i]-1]);    
            }
        }
        vector<int> ans;
        for(int i = 0; i < len; i++){
            if(nums[i]-1 != i) ans.push_back(i+1);
        }
        return ans;
    }
private:
};
```

<br/>

**解法二： 看了solutions上的一个解法，遍历一遍先把每个位置上数字对应的位置上标记为负数，然后再遍历一遍看哪个位置上还是正数就是答案了**

```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int num = abs(nums[i])-1;
            if(nums[num] >= 0) nums[num] = -nums[num];
        }
        
        for(int i = 0; i < len; i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};
```