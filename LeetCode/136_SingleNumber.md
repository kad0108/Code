**题意：给一个数组，其中所有元素都出现了两次除了一个特殊的元素，找到这个单独的元素**

<br/>
**Discuss解法：异或满足 A^A=0 以及 交换律A^B^C=A^(B^C)**

**So if the array is {2,1,4,5,2,4,1}, then it will be ```(2^1^4^5^2^4^1) => ((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5```**

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
```
<br/>

