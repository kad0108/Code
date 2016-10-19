**题意：给一颗二叉树，只包含0-9的数字，从根节点到叶子节点表示一个数，比如1->2->3表示数字123。**

**样例：**
```
For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
```

<br/>
**和Path Sum系列问题很相似，直接dfs求解**
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
    int ans;
    void dfs(TreeNode *root, int sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            sum = sum * 10 + root->val;
            ans += sum;
            return;
        }
        if(root->left) dfs(root->left, sum * 10 + root->val);
        if(root->right) dfs(root->right, sum * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
```