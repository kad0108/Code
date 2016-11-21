**题意：给一个链表，和一个数字x，把链表划分为小于x的节点都在大于等于x的节点之前，不能改变原来节点的相对位置**

**样例：**
```
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
```

<br/>
**参考discuss：直接新定义两个链表，一个链表存储比x小的节点，一个存储不小于x的节点，最后把两个链表连接起来。给链表额外添加一个头部节点，写代码时确实简洁不少。定义链表节点用new。**
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode *node1 = new ListNode(0), *node2 = new ListNode(0);
        ListNode *p1 = node1, *p2 = node2;
        while(head)
        {
            if(head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2->next;
        return node1->next;
    }
};
```