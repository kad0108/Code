**题意：给一个二叉树，找到从根节点到叶子节点路径值之和等于给定sum的所有路径。**

**样例：**
```
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
```

<br/>
**注意对于样例```[1,2] and sum = 1```，必须是到叶子节点的路径**

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
    vector<int> v;
    void dfs(TreeNode *root, int s, int sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(s+root->val == sum)
            {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
                return;
            }
        }
        if(root->left) 
        {
            v.push_back(root->val);
            dfs(root->left, s + root->val, sum);
            v.pop_back();
        }
        if(root->right)
        {
            v.push_back(root->val);
            dfs(root->right, s + root->val, sum);
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        v.clear();
        if(root == NULL) return ans;
        dfs(root, 0, sum);
        return ans;
    }
};
```

<br/>
**系列问题：112. Path Sum**

**只需要判断是否存在一条从根节点到叶子节点的路径之和等于target**
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
    bool mark;
    void dfs(TreeNode *root, int s, int sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(s+root->val == sum) mark = true;
            return;
        }
        if(root->left) dfs(root->left, s + root->val, sum);
        if(root->right) dfs(root->right, s + root->val, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        mark = false;
        dfs(root, 0, sum);
        return mark;
    }
};
```

