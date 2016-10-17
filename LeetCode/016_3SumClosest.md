**题意：给一个数组，从中找出三个数，之和最接近target。**

**样例：**
```
given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

<br/>
**两指针解法：枚举三个数之和与target比较**
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minGap = 0x7fffffff;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            for(int j = i+1, k = nums.size()-1; j < k;)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target) j++;
                else k--;
                if(abs(sum - target) < minGap) 
                {
                    minGap = abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
```

<br/>
**用multimap的lower_bound()方法，需要考虑很多地方，因为会有重复的数所以用multimap，每次去找target-nums[i]-nums[j]，都得先find到这个iterator然后从multimap中erase掉，然后再用lower_bound查找，查找完之后再把erase掉的数insert回去。做这个题用这个方法写太费劲了。。。**