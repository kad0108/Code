**题意：给一个数组，返回满足```nums[i-1]<nums[i]>nums[i+1]```的i，可以认为```num[-1] = num[n] = -∞```。**

**样例：**
```
in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2
```

<br/>
**O(n)很赞的思想**
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i]) return i-1;
        }
        return nums.size()-1;
    }
};
```

<br/>
**O(logn) 因为只要返回任意一个满足条件的索引就可以，所以可以用二分来满足logn的时间复杂度。**
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid1 = (l + r)/2;
            int mid2 = mid1+1;//因为进来while里面l!=r，所以mid2一定是合法索引
            if(nums[mid1] < nums[mid2]) l = mid2;
            else r = mid1;
        }
        return l;
    }
};
```
