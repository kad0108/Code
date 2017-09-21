**求完全二叉树的最后一个节点，给出`O((logn)^2)`的解法，思路[参考这里](https://github.com/kad0108/Code/blob/master/LeetCode/222_Count%20Complete%20Tree%20Nodes.md)**

```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode* root){
    if(root == NULL) return 0;
    return getHeight(root->left) + 1;
}

TreeNode* getLastNode(TreeNode* root){
    int h = getHeight(root);
    if(h == 0) return NULL;
    if(h == 1) return root;
    int rh = getHeight(root->right);
    if(rh == h - 1) return getLastNode(root->right);
    return getLastNode(root->left);
}

void build(vector<int> &n, TreeNode* root, int idx){
    int len = n.size();
    int l = 2 * idx + 1, r = 2 * idx + 2;

    if(l < len) {
        root->left = new TreeNode(n[l]);
        build(n, root->left, l);
    }
    if(r < len) {
        root->right = new TreeNode(n[r]);
        build(n, root->right, r);
    }
}

TreeNode* buildTree(vector<int> &n){
    if(n.empty()) return NULL;
    TreeNode *root = new TreeNode(n[0]);
    build(n, root, 0);
    return root;
}

void out(TreeNode *root){
    if(root == NULL) return;
    if(root->left) out(root->left);
    cout<<root->val<<endl;
    if(root->right) out(root->right);
}

int main(){
    vector<int> v;
    TreeNode *root = buildTree(v);
    TreeNode *lastNode = getLastNode(root);
    if(lastNode) cout<<lastNode->val<<endl;

    return 0;
}
```