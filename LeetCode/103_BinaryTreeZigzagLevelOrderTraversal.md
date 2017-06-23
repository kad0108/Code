**题意： 以zigzag的形式输出树节点**

<br/>

**样例：**

```
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

```

<br/>

**解法： bfs，需要记录每个节点的深度，最后对奇数层的节点reverse了一下**

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
 
struct Node{
    int d;
    TreeNode *tn;
    Node(int d, TreeNode *tn): d(d), tn(tn) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return ans;
        bfs(root);
        for(int i = 0; i < ans.size(); i++){
            if(i & 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
private:
    queue<Node> q;
    vector<vector<int>> ans;
    void bfs(TreeNode *root){
        q.push(Node(0, root));
        while(!q.empty()){
            Node now = q.front();
            if(ans.size() <= now.d) ans.push_back(vector<int>());
            ans[now.d].push_back(now.tn->val);
            q.pop();
            if(now.tn->left != NULL) q.push(Node(now.d+1, now.tn->left));
            if(now.tn->right != NULL) q.push(Node(now.d+1, now.tn->right));
        }
    }
};
```