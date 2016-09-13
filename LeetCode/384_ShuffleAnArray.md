**题意：给一个没有重复元素的集合，返回它的随机排列组合**

**Reference：**

[Fisher–Yates shuffle From Wikipedia](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

**洗牌算法**

1. 选中第1个元素，将其与n个元素中的任意一个交换(包括第1个元素自己)。这时排序后的第1个元素已经确定。

2. 选中第2个元素，将其与n-1个元素中作任意一个交换(包括第2个元素自己)。

3. 重复上面步骤，直到剩1个元素为止。

```
-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
```

**Proof:** 

Suppose this algorithm works, i.e. for each position i (starting from 0), the probability of any number in the range[0,i] to be at position i is 1/(1+i).

Let's look at int j = rand(i + 1):

(1) If i == j, nums[i] does not need to change its position, which has probability 1/(1+i).

(2) if i !=j, nums[i] needs to be swapped with nums[j]. 

P(any number x in the range [0,i-1] to be at position i) = P(nums[i] changes its position) * P(x is at 
position i) 

= (1-1/(1+j)) * (1/j) = 1/(1+j)

Each number has equal probability to be at any position.

<br/>
```
class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(nums);
        for(int i = ans.size()-1; i > 0; i--)
        {
            int j = rand() % (i+1);//rand() % i return num within 0 <= num < i
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
```

