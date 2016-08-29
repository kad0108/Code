**题意：判断一个int整数是不是4的乘方(the power of 4)。不使用loops/recursion。**

<br/>
**参考discuss：**

**Explaination1:**

First, Any number passes ```n^(n-1)==0``` must be powers of 2.

Second, all numbers above could be further categorized to 2 class. 

A: all numbers that are ```2^(2k+1)``` and B: all numbers that ```2^(2k)```.

Third, we could show that ```2^(2k+1)-1``` could not pass the test of ```(n-1)%3==0```. So all A are ruled out, leaving only B, which is power of 4.

**Explaination2:**

```(4^n - 1) % 3 == 0``` proof:

(1) ```4^n - 1 = (2^n + 1) * (2^n - 1)```

(2) among any 3 consecutive numbers, there must be one that is a multiple of 3 among ```2^n-1```, ```2^n```, ```2^n+1```, one of them must be a multiple of 3, and ```2^n``` cannot be the one, therefore either ```2^n-1``` or ```2^n+1``` must be a multiple of 3, and ```4^n-1``` must be a multiple of 3 as well.

```
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && ((n - 1) % 3) == 0;
    }
};
```
<br/>
**系列问题：326. Power of Three**

**without using any loop / recursion**
```
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return n > 0 && 1162261467 % n == 0;
    }
};
```

<br/>
**系列问题：231. Power of Two**

**without using any loop / recursion**
```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
```

