**题意：给一个数组，把数组分割成非空的m份，找出每一种分割方式中子数组最大和的最小值**

**样例：**
```
Input:
nums = [1,2,3,4,5]
m = 2

Output:
9

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5],
where the minimum of the largest sum among the two subarrays is only 9.
```

<br/>
**看到这种问题总会想找出所有分割方式，但是逆向思维的方式求解会更简单。**

**二分答案，发现结果和越大，分组数越少；结果和越小，分组数越大。当分组数和m相同时，就减少r，不断逼近最小值。**

```
class Solution {
public:
    //贪心，每次都让和<=mid，这样分组最少，所以有些分组是不必要的
    //比如[1, 2, 3, 4, 5]，当mid＝9时，最少分组是2组，那么不是最少分组的其他分组方法都不是必要的
    //分三组、分四组也可以让最大和为9，但这些分组情况中9肯定不会是最大和中的最小值，所以这样分组是不必要的
    int check(vector<int> &nums, long long mid)
    {
        int cot = 0;
        for(int i = 0; i < nums.size();)
        {
            int j;
            long long sum = 0;
            for(j = i; j < nums.size(); j++)
            {
                if(sum + nums[j] > mid) break;//这里保证所有分割的和都<=mid
                sum += nums[j];
            }
            if(i == j) return 0x7fffffff;//如果出现在分组时有一个组一个数都加不进去，那么就需要加大mid的值
            i = j;
            cot++;
        }
        return cot;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0x7fffffff;
        while(l <= r)
        {
            long long mid = (l + r) / 2;
            int cot = check(nums, mid);
            if(cot > m) l = mid + 1;//最少需要分的组比m大，那么应该让和增大
            else r = mid - 1;//这里如果cot==m会让和一直减小，也就是要找到分组是m个中和最小的
        }
        return int(l);
    }
};
```