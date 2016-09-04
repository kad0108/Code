**[题目链接](https://code.google.com/codejam/contest/5254487/dashboard#s=p1)**

<br/>
**Small dataset**

**已知```0<i<=n, 0<j<=n```，求```(i^a + j^b) % k == 0```。小数据解，在求幂时边乘边模**

```
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int t;
int a, b, n, k;

long long powmod(long long i, long long a)//i^a%k
{
	long long ans = 1;
	while(a)
	{
		if(a & 1) ans = ans * i % k;
		a >>= 1;
		i = i * i % k;
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
    cin>>t;
    int cot = 1;
    while(cot <= t)
    {
    	cin>>a>>b>>n>>k;
    	long long ans = 0;
    	long long m = 1000000007;
    	for(int i = 1; i <= n; i++)
    	{
    		for(int j = 1; j <= n; j++)
    		{
    			if(i != j)
    			{
    				if((powmod(i, a) + powmod(j, b)) % k == 0) ans++;
    			}
    		}
    	}
        cout<<"Case #"<<cot<<": "<<ans%m<<endl;
        cot++;
    }
    return 0;
}
```

<br/>
**Large dataset**

**大数据n是10^18，按照小数据代码的复杂度至少是O(n^2)，机器1s能跑10^7次加减运算，那就需要跑10^29s。**

**要求i,j使得```(i^a + j^b) % k == 0 => (i^a%k + j^b%k) % k == 0```**

```

```