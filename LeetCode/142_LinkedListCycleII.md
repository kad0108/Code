**系列问题：141. Linked List Cycle**

**题意：给一个链表，问是否有环**

<br/>
**两个指针，一个一次跳一步slow，一个一次跳两步fast，如果有环，两个指针一定会相遇**

**证明这两个指针一定会相遇，如果fast指针比slow指针慢一步，那么再跳一次一定会相遇，如果fast指针比slow指针慢两步，那么再跳两次一定会相遇，如果fast指针比slow指针慢k步，那么再跳k次一定会相遇。**
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

<br/>
**本题题意：找到进入环的入口点，链表没有环返回null**

<br/>
**[参考discuss](https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description)**

定义l1是head到入口点的距离，l2是入口点到相遇点的距离，c是环的长度，n是fast指针在环内转了多少圈

那么slow指针走的距离就是l1+l2，fast指针走的距离就是l1+l2+n*c，

fast指针是slow指针走的距离的两倍，则 ```2*(l1+l2) = l1+l2+n*c -> l1 = n*c-l2```

那么一个指针指向head，一个指针指向相遇点，同时走，这两个指针相遇的地方就是入口点，走的路程长度是l1.


**根据思想自己敲了一下，结果tle了，t的样例是[1,2],2指向1，因为根据上一题，为了进入while循环，slow和fast初始化不相等，在这个样例中，起始点是1相遇点是2，这样根本不会相遇找到入口点，所以t了。所以修改初始化条件，以及进入while的判断。**
```
//TLE code
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow != fast)
        {
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = head;//slow从链头出发，fast从相遇点出发
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```
**AC Code**
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;//slow从链头出发，fast从相遇点出发
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```