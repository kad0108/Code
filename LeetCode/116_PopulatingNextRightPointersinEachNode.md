**题意: 把给定的满二叉树的每个节点的next指针指向它右侧的节点，如果没有则置为null**

**样例：**

```
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
```

<br/>
**解法一：空间O(n)，n为节点数。首先想到bfs，额外需要一个pre节点记录遍历到当前位置的前一个节点。**

```
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct Node{
    int deep;
    TreeLinkNode *tn;
    Node() {};
    Node(int d, TreeLinkNode* t): deep(d), tn(t) {};
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        Node pre = Node(0, NULL);
        q.push(Node(1, root));
        while(!q.empty()){
            Node now = q.front();
            q.pop();
            if(pre.deep != now.deep){
                if(pre.tn != NULL) pre.tn->next = NULL;
            }else{
                pre.tn->next = now.tn;
            }
            pre = now;
            if(now.tn->left) q.push(Node(now.deep+1, now.tn->left));
            if(now.tn->right) q.push(Node(now.deep+1, now.tn->right));
        }
        pre.tn->next = NULL;
    }
private:
    queue<Node> q;
};
```

<br/>
**解法二：空间O(logn)。用dfs，开一个一维数组记录每个深度当前遍历到的的节点，每次都先搜索节点的右孩子，对应深度没有记录就用这个节点填充，如果有，则将当前节点的next指向对应深度记录的节点，然后更新数组。**

```
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        v.clear();
        dfs(root, 1);
    }
private:
    vector<TreeLinkNode*> v;
    void dfs(TreeLinkNode *root, int deep){
        if(root == NULL) return;
        if(v.size() < deep) v.push_back(root);
        else {
            root->next = v[deep - 1];
            v[deep - 1] = root;
        }
        dfs(root->right, deep + 1);
        dfs(root->left, deep + 1);
    }
};
```

<br/>
**解法三：空间O(1)。分治思想，对于当前节点，假设节点的左子树和右子树的所有next指针都已经算好了，那么没有算好的就是左右子树所夹着的缝隙，如样例中的1->2->5和1->3->6两条路径的next没有算好。不用算树每一层最右侧的节点，因为初始所有节点的next就都是null。**

```
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        connect(root->left);
        connect(root->right);
        fill(root->left, root->right);
    }
private:
    void fill(TreeLinkNode *a, TreeLinkNode *b){
        while(a != NULL){
            a->next = b;
            a = a->right;
            b = b->left;
        }
    }
};
```