**系列问题：219. Contains Duplicate II**

**题意：给一个数组和一个整数k，看是否能找到这样两个位置i、j，满足```nums[i]==nums[j] && |i-j|<=k```**

<br/>
**维护一个长度为k+1的sliding window，每次i>k时就移除i-k-1位置的值，然后将nums[i]插入到set中看insert方法的返回值来判断在这样一个长度的窗口中有没有满足条件的情况**

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) st.erase(nums[i-k-1]);
            pair<set<int>::iterator, bool> ret = st.insert(nums[i]);
            //pair::first返回新插入元素或集合中等价元素的迭代器
            //pair::second返回false说明set中已经有相同的值存在，新元素返回true
            if(ret.second == false) return true;
        }
        return false;
    }
};
```

<br/>
**本题题意：给一个数组和一个整数k、一个整数t，看是否能找到两个位置i、j，满足```|i-j|<=k && |nums[i]-nums[j]|<=t```**

<br/>
**使用set的lower_bound(key)方法，返回>=key的iterator，没有则返回set.end()**
```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) st.erase(nums[i-k-1]);
            set<int>::iterator it = st.lower_bound(nums[i] - t);//返回 *it >= nums[i]-t (即nums[i]-*it <= t) 的iterator
            if(it != st.end() && *it - nums[i] <= t) return true;//同时满足两个条件也就满足|nums[i]-*it|<=t
            st.insert(nums[i]);//必须在查找结束之后在将当前值插入到set中，不然会影响lower_bound的返回结果
        }
        return false;
    }
};
```