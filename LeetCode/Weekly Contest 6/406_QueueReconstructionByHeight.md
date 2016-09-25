**题意：一帮人站成一列，每个人用(h,k)来描述，h表示身高，k表示站在这个人前面身高大于等于他自己身高的人的个数。把这些属性打乱让你排好。**

**样例：**
```
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
```

<br/>
**最开始想的方法很啰嗦，用两个队列来回倒腾找出正确的序列**
```
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
class Solution {
public:
    void cal(queue<pair<int, int>> &q1, queue<pair<int, int>> &q2, pair<int, int> &a)
    {
        int cot = 0;
        bool mark = false;
        while(!q2.empty())
        {
            pair<int, int> front = q2.front();
            if(mark) 
            {
                q2.pop();
                q1.push(front);
            }
            else
            {
                if(front.first < a.first) 
                {
                    q2.pop();
                    q1.push(front);
                }
                else
                {
                    if(a.second == cot) 
                    {
                        q1.push(a);
                        mark = true;
                    }
                    else
                    {
                        q2.pop();
                        q1.push(front);
                        cot++;
                    }
                }   
            }
        }
        if(!mark && a.second == cot) q1.push(a);
    }
    void pull(queue<pair<int, int>> &q, vector<pair<int, int>> &v)
    {
        while(!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            v.push_back(tmp);
        }
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        sort(p.begin(), p.end(), cmp);
        for(int i = 0; i < p.size(); i++)
        {
            if(q1.empty()) cal(q1, q2, p[i]);
            else cal(q2, q1, p[i]);
        }
        p.clear();
        if(q1.empty()) pull(q2, p);
        else pull(q1, p);
        return p;
    }
};
```
<br/>
**lz的方法：**

根据身高从小到大排好序，然后遍历，比如说第一个人为(4,4)，那么他应该放在第五个位置，前面有四个空放置身高比他高的；

第二个人为(5,0)，那么他应该放第一个位置；

第三个人为(5,2)，他前面应该有两个空，又因为已经有(5, 0)在前面，所以他前面有一个空，放在第三个位置；

......

```
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
        sort(p.begin(), p.end(), cmp);
        vector<pair<int, int>> ans(p.size(), pair<int, int>(-1, 0));
        for(int i = 0; i < p.size(); i++)
        {
            int cot = p[i].second;
            int index;
            for(index = 0; index < p.size(); index++)
            {
                if(cot == 0) break;
                if(ans[index].first == -1 || ans[index].first == p[i].first) cot--;
            }
            while(ans[index].first != -1) index++;
            ans[index] = p[i];
        }
        return ans;
    }
};
```