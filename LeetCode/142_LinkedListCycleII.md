**系列问题：141. Linked List Cycle**

**题意：给一个链表，问是否有环**

<br/>
**两个指针，一个一次跳一步，一个一次跳两步，如果有环，两个指针一定会相遇**
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p2 != NULL && p1 != NULL)
        {
            if(p1 == p2) return true;
            p1 = p1->next;
            if(p2->next != NULL) p2 = p2->next->next;
            else return false;
        }
        return false;
    }
};
```

<br/>
**借助map存储list节点**
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> m;
        ListNode *p = head;
        while(p != NULL)
        {
            if(m.find(p) == m.end()) m[p] = true;
            else return true;
            p = p->next;
        }
        return false;
    }
};
```

**[解锁的Solution](https://leetcode.com/articles/linked-list-cycle/)**