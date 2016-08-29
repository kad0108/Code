**题意：给一个链表，返回链表中任意一个节点值。每个节点以相同的概率被选中。链表长度未知。**

**Reference：**

[Reservoir sampling From Wikipedia](https://en.wikipedia.org/wiki/Reservoir_sampling)

[蓄水池抽样](http://www.cnblogs.com/HappyAngel/archive/2011/02/07/1949762.html)

第i个数被选中的概率是```1/i```，第i个数最后被留下的概率是```第i个数被选中*第i+1不被选中*第i+2不被选中...*第n个数不被选中```，即
```
1/i * (1 - 1/(i+1)) * ... * (1 - 1/n) 
= 1/i * i/(i+1) * ... * (n-1)/n 
= 1/n
```

Choose k entries from n numbers. Make sure each number is selected with the probability of k/n。

Code for k size reservoir:

```
/*
  S has items to sample, R will contain the result
*/
ReservoirSample(S[1..n], R[1..k])
  // fill the reservoir array
  for i = 1 to k
      R[i] := S[i]

  // replace elements with gradually decreasing probability
  for i = k+1 to n
    j := random(1, i)   // important: inclusive range
    if j <= k
        R[j] := S[i]
```

<br/>
**参考[discuss](https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling)：**

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
private:
    ListNode *head;
public:
    // ListNode *head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;//this是指class Solution
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = head->val;
        ListNode *p = head->next;
        for(int i = 2; p != NULL; i++, p = p->next)
        {
            int m = rand() % i;
            if(m < 1) ans = p->val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```
**注意：**

1. rand( )返回int范围内的值，mod i 得到 0～i范围内的值。
2. 因为题目中k＝1，所以if(m < 1)也可以是判断m＝＝0～i范围内的任意一个值。
3. 不太理解ListNode *head为什么必须是私有变量。

