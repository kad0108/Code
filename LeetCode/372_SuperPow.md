**题意：计算```a^b % 1337```，a是正整数，b是很大的正整数以数组的形式给出。**

<br/>
**数论**

**欧拉函数**: 对正整数n，欧拉函数是小于等于n的数中与n互质的数的数目。
```
若n为质数，则 phi(n) = n - 1。
若m,n互质， phi(mn) = phi(m) * phi(n)
```

**欧拉定理**：若a和n为正整数，且a和n互质，则：```a^phi(n) ≡ 1 (mod n)```

```
一般在简化幂的模运算的时候，当 a和 n互质时，可对 a的指数取模 phi (n)。

设 b = p * phi(n) + q

a^b 
≡ a^(p * phi(n) + q) 
≡ (a^phi(n))^p * a^q 
≡ 1^p * a^q
≡ a^(b % phi(n)) (mod n)
```

**费马小定理**：a是整数，n是质数，且a和n互质，则：```a^(n-1) ≡ 1 (mod n)```

**互质**：```gcd(a, n) = 1```

**同余**：整数a和b模上n余数相同，则a和b同余，记为```a ≡ b (mod n)```

**参考**： 

[Euler's theorem from Wikipedia](https://zh.wikipedia.org/wiki/%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86_(%E6%95%B0%E8%AE%BA)

[Fermat's little theorem from Wikipedia](https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86)

**常用公式**: 
```
(a * b) % c = ((a % c) * (b % c)) % c
(a + b) % c = (a % c + b % c) % c
```

<br/>
**参考[discuss](https://discuss.leetcode.com/topic/50586/math-solusion-based-on-euler-s-theorem-power-called-only-once-c-java-1-line-python):  讲解很赞，使用欧拉定理实际分三种情况，但都可合并。**

```
class Solution {
public:
    //最大公约数
    int gcd(int a, int b)
    {
        while(b)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    //欧拉函数
    int phi(int n)
    {
        int num = 1;
        for(int i = 2; i < n; i++)
        {
            if(gcd(n, i) == 1) num++;
        }
        return num;
    }
    //b % p
    int mod(vector<int> &b, int p)
    {
        if(b.size() == 1) return b[0] % p;
        int digit = b[b.size() - 1];
        b.pop_back();
        return ((mod(b, p) * (10 % p) % p) + (digit % p)) % p;
    }
    //a^(b % p) % n and p = phi(n)
    int superPow(long long a, vector<int>& b) {
        int n = 1337;
        int bmod = mod(b, phi(n));
        long long ans = 1;
        while(bmod)
        {
            if(bmod & 1) ans = ans * a % n;
            bmod >>= 1;
            a = a * a % n;//here may overflow int
        }
        return ans;
    }
};
```
<br/>
**另一个容易理解的[discuss solution](https://discuss.leetcode.com/topic/50489/c-clean-and-short-solution)**
```
class Solution {
public:
    const int n = 1337;
    int powmod(int a, int b)
    {
        int ans = 1;
        while(b)
        {
            if(b & 1) ans = ans * a % n;
            b >>= 1;
            a = (long long)a * a % n;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, digit) % n;
    }
};
```