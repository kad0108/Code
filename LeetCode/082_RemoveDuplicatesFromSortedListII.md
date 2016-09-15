**题意：给一个有序列表，删除所有有重复元素的成员，使链表中只留下只出现一次的成员**

**样例：**
```
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
```

<br/>
**思路很绕，很多需要考虑的边界条件，用了点时间才写出来。**

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head;
        ListNode *pre = NULL;//记录上个节点
        int cot = 0;
        while(p->next != NULL)
        {
            if(p->val == p->next->val) cot++;
            else
            {
                if(cot)
                {
                    if(p->val == head->val) head = p->next;
                    if(pre != NULL) pre->next = p->next;
                }
                else
                { 
                    if(pre == NULL) pre = p;
                    else 
                    {
                        pre->next = p;
                        pre = p;
                    }
                }
                cot = 0;
            }
            p = p->next;
        }
        if(cot)
        {
            if(pre == NULL) return NULL;
            pre->next = NULL;
        }
        return head;
    }
};
```