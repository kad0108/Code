**类似问题：108. Convert Sorted Array to Binary Search Tree**

**把一个有序上升数组转换成平衡二叉树**

<br/>
**一开始以为要边插入边旋转保持平衡的。。。实际上是直接把中间的数做根，递归求解。**
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
    TreeNode* dfs(vector<int>& nums, int l, int r)
    {
        if(r < l) return NULL;
        int mid = (l + r)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid-1);
        root->right = dfs(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
```

<br/>
**本题题意：把一个有序上升链表转换成平衡二叉树。**

<br/>
**直接把链表中的数拿出来放进数组里，调用上一题的方法求解。**
```
class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int l, int r)
    {
        if(r < l) return NULL;
        int mid = (l + r)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid-1);
        root->right = dfs(nums, mid+1, r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode *p = head;
        while(p != NULL)
        {
            nums.push_back(p->val);
            p = p->next;
        }
        return dfs(nums, 0, nums.size()-1);
    }
};
```

<br/>
**看了discuss找链表中间数的很赞的做法，一个快指针一个慢指针，快指针每次走两步，慢指针每次走一步，快指针走到链表末尾时慢指针走到链表中间位置。**
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* dfs(ListNode *head, ListNode *tail)
    {
        if(head == tail) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != tail && fast->next->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        root->left = dfs(head, slow);
        root->right = dfs(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        return dfs(head, NULL);
    }
};
```