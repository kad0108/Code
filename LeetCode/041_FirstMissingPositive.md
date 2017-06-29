**题意： 给一个没排序的数组，找到第一个不在数组中的正整数, O(n)时间复杂度**

<br/>

**样例：**
```
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
```

<br/>

**解法： 腾讯算法面问过这个题。和448题做法一样，不过有些细节处理。因为这个题并没有告诉数组中数字的取值范围，也没有说数组有没有足够大。所以应该直接忽略不在`[1, n]`范围内的数字，n为数组大小。我的做法是交换数字到自己正确的位置上，不满足条件就标记为0，或者考虑到数组可能会有重复的数字还应该判断要交换到正确位置上本身的数字是不是已经是正确的**

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i]-1 != i){
                if(nums[i] <= n && nums[i] > 0){
                    if(nums[i] == nums[nums[i]-1]) {
                        nums[i] = 0;
                        break;
                    }
                    swap(nums[i], nums[nums[i]-1]);
                }else{
                    nums[i] = 0;
                    break;
                }
            }
        }
        
        int ans = n + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) {
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};
```
