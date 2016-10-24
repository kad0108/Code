**题意：给一个二叉树，找到两个节点的最近公共祖先，定义节点自己是自己的祖先。**

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

**样例：**
```
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

<br/>
**DFS暴力回溯求解：先去搜索节点u，回溯时对u的所有祖先节点进行标记；然后搜索节点v，回溯时判断v的祖先节点是否被标记，第一个被标记的就是u和v的最近公共祖先。**
```
class Solution {
public:
    map<TreeNode*, bool> mp;
    TreeNode *ans;
    bool dfsMark(TreeNode *&root, TreeNode *&p)
    {
        if(root == p) 
        {
            mp[root] = true;
            return mp[root];
        }
        if(root->left == NULL && root->right == NULL) return false;
        bool left = false, right = false;
        if(root->left) left = dfsMark(root->left, p);
        if(root->right) right = dfsMark(root->right, p);
        mp[root] = left || right;
        return mp[root];
    }
    bool dfsFind(TreeNode *&root, TreeNode *&q)
    {
        if(root == q) 
        {
            if(mp[root]) ans = root;
            return true;
        }
        bool left = false, right = false;
        if(root->left) 
        {
            left = dfsFind(root->left, q);
            if(ans == NULL && left) 
            {
                if(mp[root]) ans = root;
            }
        }
        if(root->right) 
        {
            right = dfsFind(root->right, q);
            if(ans == NULL && right) 
            {
                if(mp[root]) ans = root;
            }
        }
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp.clear();
        dfsMark(root, p);
        ans = NULL;
        dfsFind(root, q);
        return ans;
    }
};
```

<br/>
**看了discuss上很简洁的recursive的写法。方法返回p或q的最近祖先。如果左右子树的返回结果均不为NULL，则root就是要找的最近公共祖先；如果其中一颗子树返回NULL，则结果就是另一颗子树返回的结果。如果子树不包含p和q则返回NULL。很赞的想法啊。**
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left == NULL ? right : (right == NULL ? left : root);
    }
};
```

<br/>
**上面的解法都只适用于查询次数很少的情况，毕竟递归复杂度太高。多次查询的可以用离线的tarjan算法，在线的RMQ算法。Mark一下慢慢学。**

[几种LCA算法概述](http://blog.csdn.net/zmx354/article/details/18076975)

