**题意: 把给定的二叉树变为一个链表**

**样例：**
```
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
```

<br/>
**先记录preorder的顺序，然后再搜索树修改左节点为NULL，用preorder的输出更新树的右节点**
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
    vector<int> pre;
    void dfs(TreeNode *root)
    {
        if(root == NULL) return;
        pre.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    void flat(TreeNode *root, int i)
    {
        root->val = pre[i];
        root->left = NULL;
        if(i == pre.size()-1) return;
        if(root->right == NULL) root->right = new TreeNode(-1);
        flat(root->right, i+1);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        dfs(root);
        flat(root, 0);
    }
};
```

<br/>
**discuss上很赞的思想，代码也很简洁，反向前序遍历**
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
private:
    TreeNode *pre = NULL;
};
```