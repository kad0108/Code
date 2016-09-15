**题意：给一个有序数组，重复的元素可以重复两次，返回去除多余重复元素后数组，超出新长度的数组中的元素无关紧要。**

**样例：**
```
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, [1, 1, 2, 2, 3]
```

<br/>
**参考discuss： 很巧妙的思想**

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k < 2 || nums[i] != nums[k - 2])//数组一直在被修改，所以这里不能写为nums[i-2]
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```