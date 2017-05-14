**题意：复制复杂链表**

**O(1)空间，O(n)时间实现。**

分三步：

1. 复制每个节点并链接在原结点后

2. 更新复制结点的sibling指针

3. 将链表拆分为原链表和复制后的链表

```
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        //a->b->c to a->a'->b->b'->c->c'
        RandomListNode *p = head;
        while(p != NULL){
            RandomListNode *clone = new RandomListNode(p->label);
            clone->next = p->next;
            p->next = clone;
            p = clone->next;
        }
        //a.sibling->c to a'.sibling->c'
        p = head;
        while(p != NULL){
            RandomListNode *clone = p->next;
            if(p->random != NULL){
                clone->random = p->random->next;
            }
            p = clone->next;
        }
        //split a->a'->b->b' to a->b and a'->b'
        p = head;
        RandomListNode *cloneHead = p->next;
        while(p->next != NULL){
            RandomListNode *next = p->next;
            p->next = next->next;
            p = next;
        }
        return cloneHead;
    }
};
```