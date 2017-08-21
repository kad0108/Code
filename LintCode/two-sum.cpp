/**
* 给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
* 你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。
*/

struct Node{
    int val;
    int index;
    Node(){};
    Node(int val, int index): val(val), index(index) {};
};

bool cmp(const Node &a, const Node &b){
    if(a.val == b.val) return a.index < b.index;
    return a.val < b.val;
}

class Solution {
public:
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> nums, int target) {
        vector<Node> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back(Node(nums[i], i));
        }
        sort(v.begin(), v.end(), cmp);
        int l = 0, r = v.size()-1;
        vector<int> ans;
        while(l < r){
             int sum = v[l].val + v[r].val;
             if(sum < target) l++;
             else if(sum > target) r--;
             else {
                 ans.push_back(v[l].index+1);
                 ans.push_back(v[r].index+1);
                 sort(ans.begin(), ans.end());
                 return ans;
             }
        }
        return vector<int>();
    }
};
