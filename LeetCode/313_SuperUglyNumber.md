**题意：给一个素因数数组primes，若一个数的因数仅由给定素因数数组构成，则为ugly number。求出给定primes生成的第n个ugly number。已知1是ugly number，且给定primes是递增的。**

**样例：**
```
given primes = [2, 7, 13, 19]
then [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers
```
<br/>
**AC解：primes数组大小为k，则构造k个指针，生成数组num，初始化num[0]=1，k个指针初始化指向0，从num[k]*primes[k]中选出min加入生成数组num，同时对应被选中min值的指针右移。**

```
class Solution{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> num(n, 1);
        int k = primes.size();
        vector<int> index(k, 0);
        for(int i = 1; i < n; i++)
        {
            num[i] = num[index[0]] * primes[0];
            for(int j = 1; j < k; j++)
            {
                num[i] = min(num[i], num[index[j]] * primes[j]);
            }
            for(int j = 0; j < k; j++)
            {
                if(num[i] == num[index[j]] * primes[j]) index[j]++;
            }
        }
        return num[n - 1];
    }
};
```
<br/>
**系列问题：264. Ugly Number II**
```
//the basic idea is not dynamic program, there is no subproblem to be used to, 
//just like finding nth Fibonacci Sequence, it's basic is just recursive equation
class Solution{
public:
    int nthUglyNumber(int n)
    {
        vector<int> num(n);
        int k2 = 0, k3 = 0, k5 = 0;
        num[0] = 1;
        for(int i = 1; i < n; i++)
        {
            //in this step, the num of last change index can't be the minimum
            //and check overflow is better
            num[i] = min(min(num[k2]*2, num[k3]*3), num[k5]*5);
            if(num[i] == num[k2]*2) k2++;
            if(num[i] == num[k3]*3) k3++;
            if(num[i] == num[k5]*5) k5++;
        }
        return num[n - 1];
    }
};
```

