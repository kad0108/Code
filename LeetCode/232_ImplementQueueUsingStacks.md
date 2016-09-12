**题意: 用栈实现队列**

<br/>
```
class Queue {
public:
    stack<int> stk1;
    stack<int> stk2;
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.pop();
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int top = stk2.top();
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return top;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty();
    }
};
```
<br/>
**类似题目：225. Implement Stack using Queues**
```
class Stack {
public:
    // Push element x onto stack.
    queue<int> q1;
    queue<int> q2;
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(top);
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
```