**题意：给一个从0索引的数组，包含N个互异的数，每个数的范围在`0~N-1`，定义集合`S[K] 0 <= K < N`为`S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.`，S[K]是有限的，返回集合的最大size。**

**样例：**

```
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
```

<br/>

**暴力递归做TLE了，优化到O(n)。找到一条路径结束的标志就是成环，那么在环中所有索引得到的S[K]最大size是一样的，那么遍历数组时一些索引就不需要再重复生成S[K]这个过程了，每次成环都将对应数组中的值修改为-1**

```
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++){
            start = i;
            if(nums[i] != -1) {
                len = max(len, dfs(nums, nums[i]));
                nums[i] = -1;
            }
        }
        return len;
    }
private:
    int start;
    int dfs(vector<int>& nums, int val){
        if(val == start){
            return 1;
        }
        int tmp = nums[val];
        nums[val] = -1;
        return 1 + dfs(nums, tmp);
    }
};
```
