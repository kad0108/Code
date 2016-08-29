**题意：将链表以右侧k个位置旋转**

**样例：**
```
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
```

<br/>
**核心思想：将单向链表修改为循环链表操作**

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *tail = head;
        int len = 1;
        while(tail->next)
        {
            len++;
            tail = tail->next; 
        }
        k %= len;
        if(k == 0) return head;
        tail->next = head;//circle the link
        
        for(int i = 0; i < len - k; i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
```
<br/>
**类似题目：189. Rotate Array**
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
