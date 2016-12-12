**题意：判断一棵二叉树是不是对称的**

**样例：**
```
this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
```

<br/>
**一开始发现对称的二叉树inorder输出是个回文串，但是下面这个样例是特例不满足**
```
[1, 2, 3, null, 3, null, 2]
    1
   / \
  2   3
   \   \
   3    2
inorder输出为：[2, 3, 1, 3, 2]是回文串但是不对称
```
**然后就单独判断一下根节点的左右孩子，这样判断有点笨啊，但是AC了**
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
    vector<int> v;
    void dfs(TreeNode *root)
    {
        if(root == NULL) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        v.clear();
        dfs(root);
        for(int i = 0, j = v.size()-1; i <= j; i++, j--)
        {
            if(v[i] != v[j]) return false;
        }
        if(root->left && root->right)
        {
            if(root->left->val != root->right->val) return false;
        }
        return true;
    }
};
```

<br/>
**参考discuss的recursive解法**
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
```
<br/>
**参考discuss的iterative解法，和bfs类似，用队列来存**
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode *l = q.front();
            q.pop();
            TreeNode *r = q.front();
            q.pop();
            if(l == NULL && r == NULL) continue;
            if(l == NULL || r == NULL) return false;
            if(l->val != r->val) return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};
```