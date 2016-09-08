**系列问题：144. Binary Tree Preorder Traversal  and  94. Binary Tree Inorder Traversal**

**preorder前序遍历：根->左->右**

**inorder中序遍历：左->根->右**

**postorder后序遍历：左->右->根**

<br/>
**Iteration：参考discuss，自己没想出来迭代的解法**
```
vector<int> inorder(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    while(root != NULL || !stk.empty())
    {
        if(root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *l = stk.top();
            stk.pop();
            ans.push_back(l->val);
            root = l->right;
        }
    }
    return ans;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    while(root != NULL || !stk.empty())
    {
        if(root != NULL)
        {
            stk.push(root);
            ans.push_back(root->val);
            root = root->left;
        }
        else
        {
            TreeNode *l = stk.top();
            stk.pop();
            root = l->right;
        }
    }
    return ans;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    while(root != NULL || !stk.empty())
    {
        if(root != NULL)
        {
            stk.push(root);
            ans.push_back(root->val);
            root = root->right;
        }
        else
        {
            TreeNode *l = stk.top();
            stk.pop();
            root = l->left;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```

**Recursion**
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
vector<int> ans;
void inorder(TreeNode* root)
{
    if(root == NULL) return;
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
}

void preorder(TreeNode* root)
{
    if(root == NULL) return;
    ans.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
}

void postorder(TreeNode* root)
{
    if(root == NULL) return;
    dfs(root->left);
    dfs(root->right);
    ans.push_back(root->val);
}
```