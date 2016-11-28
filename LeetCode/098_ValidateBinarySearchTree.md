**题意：判断一个二叉树是否是二叉搜索树。左子树的节点值必须都小于root节点值，右子树的节点值必须都大于root节点值。**

<br/>
**一开始想法是每次去探索左右子树，返回左子树的最大值和右子树的最小值，如果满足```root > left_max && root < right_min```，则返回true。但是，回溯时再判断，而且深搜还会有多个返回值（left_max,root_min,bool），怎么写怎么不对。。。然后看了discuss，需要逆向思维一下！每次向下深搜，都传入当前节点应该满足的范围即可。左子树就限制最大值，右子树限制最小值。**

BST是严格要求```left < root > right```的，等于不满足。

节点值的返回是INT_MIN~INT_MAX，所以限制参数需要传入LONG_MIN和LONG_MAX，不然像样例[2147483647]是BST，但返回了false。

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
    bool dfs(TreeNode *root, long long _min, long long _max)
    {
        if(root == NULL) return true;
        if(root->val >= _max || root->val <= _min) return false;
        return dfs(root->left, _min, root->val) && dfs(root->right, root->val, _max);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
```