**系列问题：96. Unique Binary Search Trees 给一个n，输出由1～n这些数字构成的二叉搜索树。**

**样例：**
```
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

<br/>
**dp解：枚举根节点i，那么左子树由1～i-1构成，右子树由i+1～n构成，对于左子树又可以枚举根节点...以此类推**

**dp[i]表示由i个数构成的二叉搜索树有多少个，则有**
```
dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + ... + dp[i-1]*dp[n-i] + ... + dp[n-1]*dp[0]
        根节点为1        根节点为2               根节点为i                根节点为n
```
```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;//因为计算后面的BST需要乘dp[0]的值
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
```

<br/>
**本题题意：输出由1～n构成的二叉搜索树**

**dfs解：每次调用dfs需要做的就是根据给的节点个数i去枚举根节点，那么还需要知道根节点的值，就再传一个参数表示这棵树中数字的区间起始值l，也就是说要用[l, l+i-1]这些数构成BST**
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
    vector<TreeNode*> dfs(int i, int l)//i是节点个数，k是子节点区间起始值
    {
        vector<TreeNode*> v;
        if(i == 0) 
        {
            v.push_back(NULL);
            return v;
        }
        /*这个条件不加也可以
        if(i == 1)
        {
            TreeNode *leaf = new TreeNode(l);
            v.push_back(leaf);
            return v;
        }
        */
        int r = l + i - 1;
        for(int j = l; j <= r; j++)
        {
            vector<TreeNode*> left = dfs(j-l, l);//会出现调用节点个数为0的情况
            vector<TreeNode*> right = dfs(r-j, j+1);
            for(int p = 0; p < left.size(); p++)
            {
                for(int q = 0; q < right.size(); q++)
                {
                    TreeNode *root = new TreeNode(j);//这句不能放在枚举根节点那层循环里，必须每次定义一个新的根节点，不然一直修改同一个根节点指向的左右子树，导致后面的结果覆盖前面的结果
                    root->left = left[p];
                    root->right = right[q];
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        vector<TreeNode*> ans = dfs(n, 1);
        return ans;
    }
};
```
```