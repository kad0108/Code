**题意：给一个二叉树，将节点从左到右按层输出**

**样例：**
```
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
```

<br/>
**因为不知道树有多深，不能事先给ans开辟空间，所以在层数大于ans的size时，不能直接访问下标。**
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
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int level)
    {
        if(level > ans.size()-1)
        {
            ans.push_back(vector<int>(1, root->val));
        }
        else
        {
           if(level != 0) ans[level].push_back(root->val); 
        }
        if(root->left == NULL && root->right == NULL) return;
        if(root->left) dfs(root->left, level+1);
        if(root->right) dfs(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        if(root == NULL) return ans;
        ans.push_back(vector<int>(1, root->val));
        dfs(root, 0);
        return ans;
    }
};
```

**系列问题：107. Binary Tree Level Order Traversal II**