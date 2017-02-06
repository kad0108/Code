> 求两个正整数的最大公约数

**辗转相除法: 两个正整数a和b(a>b)的最大公约数等于a%b和b的最大公约数**

```c++
int gcd(int a, int b){
    if(a % b == 0) return b;
    if(a < b) {
        int c = b;
        b = a;
        a = c;
    }
    return gcd(b, a%b);
}
```

**更相减损数：两个正整数a和b(a>b)的最大公约数等于a－b的差值c和较小数b的最大公约数**

```c++
int gcd(int a, int b){
    if(a == b) return b;
    if(a < b){
        int c = b;
        b = a;
        a = c;
    }
    return gcd(b, a-b);
}
```

**最小公倍数＝m*n/gcd**