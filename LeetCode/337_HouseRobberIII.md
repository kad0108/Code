**系列问题：198. House Robber**

**题意：给一个数组，每个元素表示每个房子里有多少money，同一晚上不能去相邻的两家偷money，问最多能偷多少。**

<br/>
**dp[i]表示从第一个房子到i为止最多能偷的money，分两种情况偷第i家和不偷第i家，偷第i家就从dp[i-2]转移过来，不偷第i家，状态从dp[i-1]转移过来**
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(i - 2 >= 0) dp[i] = max(dp[i], dp[i-2] + nums[i]);
            else dp[i] = max(dp[i], nums[i]);
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp.back();
    }
};
```

<br/>
**系列问题：213. House Robber II**

**题意：这次房子不是一列了，而是围成了一圈，也就是数组中第0房子和n-1房子相邻，问最多能偷多少。**

<br/>
**在第0个房子和n-1房子这里破环，看第0个房子的状态，偷还是不偷，偷的话就是看0~n-2这些房子，不偷的话看1~n-1这些房子**
```
class Solution {
public:
    int handle(vector<int> &nums, int l, int r)
    {
        int pre2 = 0, pre1 = 0;//pre2当前位置往前数第2个位置，pre1当前位置的前一个位置
        for(int i = l; i <= r; i++)    
        {
            int tmp = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = tmp;
        }
        return pre1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(handle(nums, 0, n-2), handle(nums, 1, n-1));
    }
};
```

<br/>
**系列问题：337. House Robber III**

**题意：这次房子是一棵二叉树，入口为根节点，同一晚上不能偷相连的两个房子，问最多能偷多少money**

<br/>
**在树上做dp，每个节点的dp状态都由它的子节点的dp状态转移过来。dp[i]表示以i为根节点的子树能偷到的最多的money；dp[i][0]表示不偷i这个节点，dp[i][1]表示偷i这个节点。dp[root][0]应该是它的左右子节点的状态最大值之和，子节点可以是0也可以是1；dp[root][1]则只能由左右子节点都是0的状态转移过来。**
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> dfs(TreeNode *root)//dp[i]的状态以i为根节点的子树能得到的最大和
    {
        if(root == NULL) return vector<int>(2, 0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        vector<int> dp(2, 0);
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);//dp[0]表示不要根节点的值
        dp[1] = left[0] + right[0] + root->val;//dp[1]表示要根节点的值
        return dp;
    }
    int rob(TreeNode* root) {
        vector<int> dp = dfs(root);
        return max(dp[0], dp[1]);
    }
};
```
