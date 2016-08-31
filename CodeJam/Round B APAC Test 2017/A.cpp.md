**[题目链接](https://code.google.com/codejam/contest/5254487/dashboard#s=p0)**

**贪心思想：可以看出```()()...```这样形式的string比其他组合的balanced数更多。归纳得到解```(n+1)n/2```**

**Large dataset**

```
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int l, r;

int main()
{
    freopen("in.txt", "r", stdin);
    cin>>t;
    int cot = 1;
    while(cot <= t)
    {
        cin>>l>>r;
        long long n = min(l, r);
        long long ans = n * (n + 1) / 2;
        cout<<"Case #"<<cot<<": "<<ans<<endl;
        cot++;
    }
    return 0;
}
```