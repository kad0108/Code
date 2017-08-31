**系列题目：496. Next Greater Element I**

**题意：给两个数组，数组1是数组2的子集，找到数组1中在数组2中对应的下一个较大的值。**

**样例：**
```
Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
    
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
```

<br/>

**O(n)解法：遍历数组2，维护一个单调递减栈，每次栈顶元素比要入栈元素大，就弹栈并记录栈顶元素对应的下一个较大的值。然后遍历数组1，没有找到对应的较大值则为-1。**
```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mp;
        stack<int> stk;
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && stk.top() < nums[i]){
                mp[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(nums[i]);
        }
        vector<int> ans;
        for(int i = 0; i < findNums.size(); i++){
            if(mp[findNums[i]]) ans.push_back(mp[findNums[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
```

<br/>




**本题题意：给一个环形数组（最后一个值的下一位是数组的第一个值），找到数组中每一个值的下一个较大的值。**

**样例：**
```
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
```

<br/>

**O(n)解法：和上一题一样，维护一个递减的单调栈，栈中记录索引。因为是环形数组，遍历范围len*2。**
```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int len = nums.size();
        vector<int> ans(len, -1);
        for(int i = 0; i < len * 2; i++){
            int num = nums[i % len];
            while(!stk.empty() && nums[stk.top()] < num){
                ans[stk.top()] = num;
                stk.pop();
            }
            if(i < len) stk.push(i);
        }
        return ans;
    }
};
```

