**题意：翻转列表**

<br/>
**Iteration**

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p = head;
        ListNode *mid = NULL;
        bool mark = false;
        while(p->next)
        {
            ListNode *tmp = p->next->next;
            ListNode *tmp2 = p->next;
            p->next = mid;
            mid = tmp2;
            mid->next = p;
            if(tmp == NULL) 
            {
                head = mid;
                mark = true;
                break;
            }
            else p = tmp;
        }
        if(!mark)
        {
            p->next = mid;
            head = p;
        }
        return head;
    }
};
```
<br/>
**Recursion**
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
    ListNode *h;
    bool mark;
    void dfs(ListNode *p, ListNode *head)
    {
        if(p == NULL)
        {
            mark = true;
            return;
        }
        dfs(p->next, head);
        if(mark) 
        {
            h = p;
            mark = false;
        }
        else p->next->next = p;
        if(p == head) p->next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        mark = false;
        dfs(head, head);
        return h;
    }
};
```

**系列题目：92. Reverse Linked List II**

**题意：给一个链表，翻转给定区间，1<=m<=n<=len**

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
    void dfs(ListNode *a, ListNode *b)
    {
        if(a == b) return;
        dfs(a->next, b);
        a->next->next = a;
    }
    ListNode* reverseBetween(ListNode* head, int begin, int end) {
        if(begin == end) return head;
        ListNode *p = head;
        ListNode *pre = NULL, *after = NULL;
        ListNode *a, *b;
        for(int cot = 1; p != NULL; p = p->next, cot++)
        {
            if(cot == begin) a = p;
            if(begin != 1 && cot == begin - 1) pre = p;
            if(cot == end) 
            {
                b = p;
                if(begin == 1) head = b;
            }
            if(cot == end + 1) after = p;
        }
        dfs(a, b);
        if(pre != NULL) pre->next = b;
        a->next = after;
        return head;
    }
};
```