**题意：求int类型的x的平方根**

**直接能想到用位运算好开森~\(^o^)/~**

**效率比暴力不知道高到哪里去~~，while循环最多循环16次，所以复杂度是O(1)。**
```
class Solution {
public:
    long long pow(long long x)
    {
        return x * x;
    }
    int mySqrt(long long x) {
        if(x == 0) return 0;
        long long a = 1, cot = 1;
        //先找到最高位的1
        while(cot < 31)
        {
            if(pow(a << 1) > x) break;//注意这句的运算会爆int
            a <<= 1;
            cot++;
        }
        //然后从高位向低位试探结果
        int b = a >> 1;
        while(b)
        {
            if(pow(a + b) <= x) a += b;
            b >>= 1;
        }
        return a;
    }
};
```
<br/>
**相似的题目：Pow(x, n)**
```
/*
* 对幂进行二进制分解
* 需要注意：幂可能小于0，在对幂取反时可能会超int
*/
class Solution {
public:
    double myPow(double x, long long n) 
    {
        double ans = 1;
        bool mark = n < 0 ? true : false;
        n = abs(n);
        while(n > 0)
        {
            if(n & 1) ans *= x;
            n >>= 1;
            x *= x;
        }
        if(mark) ans = 1.0 / ans;
        return ans;
    }
};
```