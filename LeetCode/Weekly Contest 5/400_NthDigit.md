**题意：从1开始的正整数序列，找到第n位数字。**

**样例：**
```
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
```

<br/>
第一次做法直接去遍历n，然后找到nth digit对应的实际数字和从低位开始数第几位。然后TLE了

第二次做法开个11位的数组记录，比如第3个元素表示长度为3位的数字100对应的起始数，也是为了找到nth digit对应的实际数字和这个数字哪一位，但是结果一些样例过不了

**AC解法：参考了discuss，同样是要找到nth digit对应的数字start，以及对应这个数字第几位(n-1)%len，以及这个数字是几位len，然后用了to_string方法把start转换成字符串这样就好输出第几位的值了**

```
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        long long cot = 9;
        long long start = 1;
        while(n > cot * len)
        {
            n -= cot * len;
            len++;
            cot *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n-1)%len] - '0';
    }
};
```