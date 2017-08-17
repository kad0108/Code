**题意：找出无序数组中第k大的数，注意不是第k个不同的值, `Given [3,2,1,5,6,4] and k = 2, return 5.`**

<br/>
**解法一：O(nlogn) time & O(1) space.**

```
bool cmp(int a, int b)
{
    return a > b;
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};
```
<br/>

**解法二：O(n) best case / O(n^2) worst case &  O(1) space. 快排的划分操作可以得到x，使得左侧的数比它小，右侧的数比它大。要想得到第k大的数，如果x比n－k小，那说明第k大的数一定在x 的右侧。partition复杂度是O(n)**

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n-1;
        int num = partition(l, r, nums);
        while(num != n-k){
            if(num < n - k) l = num + 1;
            else r = num - 1;
            num = partition(l, r, nums);
        }
        return nums[num];
    }
private:
    int partition(int l, int r, vector<int>& nums){
        int tmp = nums[l];
        while(l < r){
            while((l < r) && (nums[r] > tmp)) r--;
            if(l < r) nums[l++] = nums[r];
            while((l < r) && (nums[l] < tmp)) l++;
            if(l < r) nums[r--] = nums[l];
        }
        if(l == r) nums[l] = tmp;
        return l;
    }
};
```

<br/>
**解法三：O(nlogk) time & O(k) space. 维护一个k大小的小顶堆，存放前k大的数。最后的得到的堆顶元素就是第k大的数。**

```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```
