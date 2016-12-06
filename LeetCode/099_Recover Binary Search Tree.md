**题意：给一个二叉搜索树，其中两个节点交换了位置，让你恢复正确的BST且不改变树的结构**

**O(n) space：二叉搜索树的一个特点就是中序遍历输出是递增的，那么只需要找到破坏这个规律的两个数即可。因为中序遍历序列是递增的，那么一定是一个大数被交换到前面，一个小数被交换到了后面，所以如果相邻的两个数```a[i]>a[i+1]```，那么被交换的大数一定是前一个，小数一定是后一个（在大数已经找到的情况下）。这时还有个bug，如果被交换的这两个数在中序遍历的输出中是相邻的，大数会被找到，小数则还是null，就需要单独处理一下。**

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
    vector<TreeNode*> rec;
    void recoverTree(TreeNode* root) {
        rec.clear();
        inorder(root);
        TreeNode *one = NULL, *two = NULL;
        int index = -1;
        for(int i = 0, len = rec.size(); i < len-1; i++)
        {
            if(rec[i]->val > rec[i+1]->val)
            {
                if(one == NULL) index = i, one = rec[i];
                else if(two == NULL) two = rec[i+1];
            }
        }
        if(one != NULL)
        {
            if(two == NULL) two = rec[index+1];// 单独处理两个数在inorder输出中相邻的情况
            int temp = one->val;
            one->val = two->val;
            two->val = temp;
        }
    }
    void inorder(TreeNode *root)
    {
        if(root == NULL) return;
        inorder(root->left);
        rec.push_back(root);
        inorder(root->right);
    }
};
```
<br/>
**O(1) space**
```
class Solution {
public:
    TreeNode *one, *two, *pre;
    void recoverTree(TreeNode* root) {
        one = NULL;
        two = NULL;
        pre = new TreeNode(INT_MIN);
        inorder(root);
        if(one != NULL)
        {
            int tmp = one->val;
            one->val = two->val;
            two->val = tmp;
        }
    }
    void inorder(TreeNode *root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(one == NULL && pre->val >= root->val) one = pre;
        if(one != NULL && pre->val >= root->val) two = root;
        pre = root;
        inorder(root->right);
    }
};
```