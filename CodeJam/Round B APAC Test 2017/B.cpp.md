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

```
(i^a + j^b) % k == 0 
=> (i^a % k + j^b % k) % k == 0 
=> ((i % k)^a % k + (j % k)^b % k) % k == 0
=> (partA + partB) % k == 0
```

**求满足上面条件的```(i, j)```对，可以转化为找partA和partB的余数组合，```eg:(partA=0, partB=0),(partA=1, partB=k-1)...(partA=k-1, partB=1)```，其中partA和partB的范围是0~k-1，```(i%k)```和```(j%k)```的范围也是```0~k-1```，那么就可以枚举(i%k)来计算partA每一个余数对应的i的个数，partB同理。**

**枚举(i%k)，```i```的范围是```1~n```，那么**
```
i%k=0:   k, 2k...pk<=n         => p=n/k
i%k=1:   1, k+1,2k+1...pk+1<=n => p=n/k+1
...
i%k=k-1: k+k-1,2k+k-1...pk+k-1 => p=?

因为n%k可能并不能到k-1，所以(i%k)<=(n%k)时p=n/k+1，另外i!=0，所以(i%k)=0时p=n/k
eg: n=8 k=5
```

**还要去掉```i==j```的情况，cote数组记录i==j时(partA + partB) % k每一个余数对应的i的个数，因为数组中已经加入了cot[i]的值，所以```cote[0]```就是满足```((i%k)^a%k + (i%k)^b%k)%k==0```情况下i的个数**

```
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
long long a, b, n, k;

const int K = 100005;
long long cot[K];//1~n中％k取值为0~k-1的个数
long long cota[K];//记录(i%k)^a%k取值0~k-1时i的个数
long long cotb[K];
long long cote[K];//while i == j

long long powmod(long long a, long long b, long long k)//a^b%k
{
    if(b == 0) return 1 % k;
    long long ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % k;
        b >>= 1;
        a = a * a % k;
    }
    return ans;
}

int main()
{
    cin>>t;
    int tt = 1;
    while(tt <= t)
    {
        cin>>a>>b>>n>>k;
        const long long mod = 1e9+7;
        long long ans = 0;

        memset(cot, 0, sizeof(cot));
        memset(cota, 0, sizeof(cota));
        memset(cotb, 0, sizeof(cotb));
        memset(cote, 0, sizeof(cote));

        for(int i = 0; i < k; i++)
        {
            cot[i] = (n / k) % mod;
            if(i > 0 && i <= (n % k)) cot[i] = (cot[i] + 1) % mod;
        }
        for(int i = 0; i < k; i++)
        {
            long long tmpa = powmod(i, a, k);
            long long tmpb = powmod(i, b, k);
            long long tmpe = (tmpa + tmpb) % k;
            cota[tmpa] = (cota[tmpa] + cot[i]) % mod;
            cotb[tmpb] = (cotb[tmpb] + cot[i]) % mod;
            cote[tmpe] = (cote[tmpe] + cot[i]) % mod;
        }
        for(int i = 0; i < k; i++)
        {
            long long j = (k - i) % k;
            ans = (ans + cota[i] * cotb[j] % mod) % mod;
        }
        ans = (ans - cote[0] + mod) % mod;

        cout<<"Case #"<<tt<<": "<<ans<<endl;
        tt++;
    }

    return 0;
}
```
**注意：**

1. powmod函数中当```b=0,k=1```时，会直接返回ans的初始化值1，实际应该返回0，所以应该加上语句```if(b == 0) return 1 % k;```。

2. 因为输入的n很大，在计算```cota,cotb,cote```数组时一直在做加法运算可能会爆long long，所以应该存储```% mod```之后的值。

3. partA余数为p时i的个数有cota[p]，partB余数为k-p时j的个数有cotb[k-p]，那么组合数就为```cota[p]*cotb[k-p]```。

4. 因为上面计算cota,cotb数组是模mod的值，所以求ans时应该是```ans=(ans%mod + cota[i]*cotb[j]%mod)%mod```。

5. 然后要去掉```i==j```的情况，```ans-cote[0]```可能会是负数，所以加上一个mod再模mod。