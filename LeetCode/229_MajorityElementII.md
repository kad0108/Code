**题意：给一个数组，找到其中所有出现次数大于n/3次的数字。线性时间以及O(1)空间内完成。**

<br/>
**直接给数组排序，然后遍历找。O(nlogn) time.**
```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 0) return nums;
        
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int cot = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1]) cot++;
            else
            {
                if(cot > n/3) ans.push_back(nums[i-1]);
                cot = 1;
            }
        }
        if(cot > n/3) ans.push_back(nums.back());
        return ans;
    }
};
```

<br/>
**[Boyer-Moore Algorithm](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html)  O(1) extra space and O(N) time. 两个candidate的方法还是没有理解透彻。**
```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return nums;
        
        int candidate1 = 0, cot1 = 0;
        int candidate2 = 0, cot2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(cot1 > 0 && nums[i] == candidate1) cot1++;
            else if(cot2 > 0 && nums[i] == candidate2) cot2++;
            else if(cot1 == 0) candidate1 = nums[i], cot1++;
            else if(cot2 == 0) candidate2 = nums[i], cot2++;
            else 
            {
                //需要同时消掉一个candidate1和一个candidate2
                cot1--;
                cot2--;
            }
        }
        // cout<<candidate1<<" "<<candidate2<<endl;
        cot1 = 0, cot2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(candidate1 == nums[i]) cot1++;
            else if(candidate2 == nums[i]) cot2++;
        }
        vector<int> ans;
        if(cot1 > n/3) ans.push_back(candidate1);
        if(cot2 > n/3) ans.push_back(candidate2);
        return ans;
    }
};
```

<br/>
**系列题目：169. Majority Element 找到唯一的数出现次数大于n/2**

**map存储 O(n) time and O(n) space.**
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        map<int, int>::iterator it;
        int ans;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(it->second > n/2) ans = it->first;
        }
        return ans;
    }
};
```
<br/>
**Boyer-Moore Algorithm O(n) time and O(1) space.**
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0, cot = 0;
        for(int i = 0; i < n; i++)
        {
            if(cot == 0) candidate = nums[i];
            if(candidate == nums[i]) cot++;
            else cot--;
        }
        /* 正常在找到这个数之后还需要验证是否出现次数确实严格大于n/2,
        * 但是题目说一定存在这个数所以就不需要验证了
        cot = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == candidate) cot++;
        }
        */
        return candidate;
    }
};
```