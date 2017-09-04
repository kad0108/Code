## 知识点记忆

一段时间不敲C++，语法就能忘差不多。。。

## priority_queue

优先队列的内部实现是堆，默认维护的是大顶堆以及less(<)。对于自定义的struct类型的优先队列，需要再struct内部重载小于号，这样优先队列才会比较两个节点类型。

可以定义`priority_queue<int, vector<int>, greater<int>> pq`然后重载大于号来实现。

```
// 重载小于号，返回 a < b 是大顶堆，返回 a > b 是小顶堆
struct Node
{
    int x, y;
    Node(){}
    Node(int xx, int yy): x(xx), y(yy) {}
    bool operator < (const Node &o) const
    {
        return x > o.x;//小顶堆
    }
};
priority_queue<Node> pq;
pq.push(Node(1,2));
```

