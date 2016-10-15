**题意：找到两个链表的相交点，没有返回null**

**样例：**
```
the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
```

<br/>
**两个链表相交之后长度都是一样的，那么找到两个链表长度差多少，然后让长的链表先走这个长度，然后就可以进行比较了。**
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
    void handle(ListNode *&p, ListNode *&headA)
    {
        int cot = 0;
        while(p != NULL)
        {
            p = p->next;
            cot++;
        }
        p = headA;
        while(cot--)
        {
            p = p->next;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != NULL && pb != NULL)
        {
            if(pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        int moreLen = 0;
        if(pa != NULL) 
        {
            handle(pa, headA);
            pb = headB;
        }
        else if(pb != NULL) 
        {
            handle(pb, headB);
            pa = headA;
        }
        while(pa != NULL && pb != NULL)
        {
            if(pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
};
```

<br/>
**参考discuss，很赞的写法，两个指针同时走，谁先走到链表尾就指向另一个链表的头部继续走，这样两个链表有交点则两指针一定会在交点相遇，如果没有交点则最终会到达两个指针都指向null。**
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(1)
        {
            if(pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
            //如果两个链表没有交点，最终会到达pa=null,pb=null的状态，此时必须返回不然TLE
            if(pa == NULL && pb == NULL) return NULL;
            if(pa == NULL) pa = headB;
            if(pb == NULL) pb = headA;
        }
        return NULL;
    }
};
```
