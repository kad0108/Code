**题意：返回二叉树中左叶子的和，注意是叶子节点**

**样例：**
```
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
```
<br/>
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
    int sum;
    bool mark;
    void dfs(TreeNode *root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(mark) sum += root->val;
            return;
        }
        if(root->left)
        {
            mark = true;
            dfs(root->left);
            mark = false;
        }
        if(root->right)
        {
            mark = false;
            dfs(root->right);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        sum = 0;
        dfs(root);
        return sum;
    }
};
```