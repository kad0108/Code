**题意：求出二叉树的最大深度。**

<br/>
**解法一：直接暴力dfs找最大深度**

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
class Solution{
public:
    int maxd;
    void dfs(TreeNode *root, int d)
    {
        if(root->left == NULL && root->right == NULL) 
        {
            maxd = max(maxd, d);
            return;
        }
        if(root->left != NULL) 
        {
            dfs(root->left, d + 1);//注意这里不能写成d++或++d，因为这样就修改了这一层dfs的d值。
        }
        if(root->right != NULL)
        {
            dfs(root->right, d + 1);
        }
    }
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        maxd = 1;
        dfs(root, 1);
        return maxd;
    }
};
```
<br/>
**解法二：每个节点的深度都是其左右孩子的最大深度＋1**
```
class Solution{
public:
    int dfs(TreeNode *root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) 
        {
            return 1;
        }
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
    int maxDepth(TreeNode* root){
        return dfs(root);
    }
};
```
<br/>
**类似题目：111. Minimum Depth of Binary Tree。不同的是，如果节点只有一个孩子，那么最小深度就是孩子的深度。**

**DFS写法**
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
    int dfs(TreeNode *root)
    {
        if(root == NULL) return 0x7fffffff;
        if(root->left == NULL && root->right == NULL) 
        {
            return 1;
        }
        return min(dfs(root->left), dfs(root->right)) + 1;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root);
    }
};
```
**BFS写法，实际上做这个问题，bfs是高效的，因为每层每层的看节点，只要碰到节点没有子节点那么一定是最小深度。**
```
class Solution {
public:
    struct Node
    {
        TreeNode *root;
        int level;
    };
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<Node> q;
        q.push(Node{root, 1});
        while(!q.empty())
        {
            Node now = q.front();
            q.pop();
            if(now.root->left) q.push(Node{now.root->left, now.level+1});
            if(now.root->right) q.push(Node{now.root->right, now.level+1});
            if(now.root->left == NULL && now.root->right == NULL) 
            {
                return now.level;
            }
        }
        return 0;
    }
};
```