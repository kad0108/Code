/**
给定一个可能具有重复数字的列表，返回其所有可能的子集
如果 S = [1,2,2]，一个可能的答案为：
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


struct Node{
    int val;
    int cot;
    Node(int val, int cot): val(val), cot(cot) {};
};

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        if(nums.empty()) {
            ans.push_back(vector<int>());
            return ans;
        }
        ans.clear();
        v.clear();
        vector<Node> vn;
        sort(nums.begin(), nums.end());
        int cot = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]){
                vn.push_back(Node(nums[i-1], cot));
                cot = 1;
            }else{
                cot++;
            }
        }
        if(vn.empty() || vn.back().val != nums.back()) vn.push_back(Node(nums.back(), cot));
        dfs(0, vn);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> v;
    void dfs(int i, vector<Node> &vn){
        if(i >= vn.size()){
            ans.push_back(v);
            return;
        }
        for(int k = 0; k <= vn[i].cot; k++){
            for(int p = 0; p < k; p++){
                v.push_back(vn[i].val);
            }
            dfs(i+1, vn);
            for(int p = 0; p < k; p++){
                v.pop_back();
            }
        }
    }
};
