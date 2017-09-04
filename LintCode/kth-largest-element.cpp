/**
* 在数组中找到第k大的元素
* 给出数组 [9,3,2,4,8]，第三大的元素是 4
*/

// 解法一：优先队列
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        priority_queue<int> pq;
        for(int i = 0, len = nums.size(); i < len; i++){
            pq.push(nums[i]);
            if(pq.size() > len - k + 1) pq.pop();
        }
        return pq.top();
    }
};

// 解法二：借助快排划分操作
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        int len = nums.size();
        int l = 0, r = len-1;
        int q = partition(l, r, nums);
        while(q != len - k){ // 这里注意q是索引，索引从0开始，所以条件不是n-k+1
            if(q < len - k) l = q + 1;
            else r = q - 1;
            q = partition(l, r, nums);
        }
        return nums[q];
    }
private:
    int partition(int l, int r, vector<int> &nums){
        int tmp = nums[l];
        while(l < r){
            while((l < r) && (tmp < nums[r])) r--;
            if(l < r) nums[l++] = nums[r];
            while((l < r) && (tmp > nums[l])) l++;
            if(l < r) nums[r--] = nums[l];
        }
        if(l == r) nums[l] = tmp; // 好像每次都忘记这一步操作
        return l;
    }
};
