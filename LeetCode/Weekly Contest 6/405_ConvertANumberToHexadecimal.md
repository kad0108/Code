**题意：将一个整数转换为十六进制，负数的转换用到二进制补码(two’s complement)，要求输出字母为小写字母，且非0的输入输出不能有前导0。**


**样例：**
```
26 -> "1a"
-1 -> "ffffffff"
```
<br/>
**不管是用什么形式的表示出来，在计算机中存储都是以二进制位存储的。所以负数的转换直接可以将int整型转换为unsigned int**
```
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return string(1, '0');
        unsigned int a = num;
        string ans;
        while(a)
        {
            int tmp = a % 16;
            if(tmp <= 9) ans.push_back(tmp + '0');
            else ans.push_back(tmp - 10 + 'a');
            a /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

