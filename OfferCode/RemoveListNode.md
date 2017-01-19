> 题目描述
> 删除链表某个节点

**需要考虑链表为空、删除节点为头节点**

```c++
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* &head, int delVal) {
        if(head == NULL) return;
        ListNode *delNode = NULL;
        if(head->val == delVal){
            delNode = head;
            head = head->next;
            return;
        }
        ListNode *p = head;
        while(p->next != NULL){
            if(p->next->val == delVal){
                delNode = p->next;
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        if(delNode != NULL) delete delNode;
	}
};

void out(ListNode *head){
    ListNode *p = head;
    while(p != NULL){
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    Solution so;
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i = 2; i < 5; i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    out(head);
    so.deleteNode(head, 6);
    out(head);
    return 0;
}

```