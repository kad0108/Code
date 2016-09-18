**[题目链接](https://code.google.com/codejam/contest/11274486/dashboard#s=p0)**

**Large dataset**

```
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int t, n;

struct Node
{
    string s;
    vector<bool> val;
    int cot;
    Node(){ //构造函数初始化
        val.assign(26, 0);
        cot = 0;
    }
};

int main()
{
    int tt = 1;
    cin>>t;
    while(tt <= t)
    {
        cin>>n;
        getchar(); //读入回车
        vector<Node> v;
        for(int i = 0; i < n; i++)
        {
            Node a;
            getline(cin, a.s); //读入一整行带空格的string
            for(int k = 0; k < a.s.size(); k++)
            {
                char ch = a.s[k];
                if(ch >= 'A' && ch <= 'Z') a.val[ch-'A'] = 1;
            }
            for(int k = 0; k < a.val.size(); k++)
            {
                if(a.val[k]) a.cot++;
            }
            v.push_back(a);
        }
        int maxn = -0x7fffffff;
        int index;
        for(int i = 0; i < n; i++)
        {
            if(v[i].cot > maxn) 
            {
                index = i;
                maxn = v[i].cot;
            }
            else if(v[i].cot == maxn) 
            {
                if(strcmp(v[i].s.c_str(), v[index].s.c_str()) < 0)
                {
                    index = i;
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<v[index].s<<endl;
        tt++;
    }
    
    return 0;
}
```