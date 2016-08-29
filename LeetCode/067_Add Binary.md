**题意：给两个二进制字符串，返回求和（二进制字符串）**

**样例：**
```
a = "11"
b = "1"
Return "100"
```

**自己写的，代码冗余，很胖**

```
class Solution {
public:
    int func(string &c, string &a, int i, int add)
    {
        while(i < a.size())
        {
            int temp = a[i] - '0' + add;
            c.push_back((temp % 2) + '0');
            add = temp / 2;
            i++;
        }
        return add;
    }
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i, add = 0;
        string c;
        for(i = 0; i < min(a.size(), b.size()); i++)
        {
            int temp = (a[i] - '0') + (b[i] - '0') + add;
            c.push_back((temp % 2) + '0');
            add = temp / 2;
        }
        if(i < a.size()) add = func(c, a, i, add);
        if(i < b.size()) add = func(c, b, i, add);
        if(add) c.push_back(add + '0');
        reverse(c.begin(), c.end());
        return c;
    }
};
```
<br/>
**discuss上的写法，代码很简洁，效率一样**
```
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size(), lenb = b.size();
        int add = 0;
        string c;
        while(lena || lenb || add)
        {
            //lena--和lenb--只能在len!=0时执行
            add += (lena ? a[(lena--) - 1] - '0' : 0) + (lenb ? b[(lenb--) - 1] - '0' : 0);
            //字符串相加是拼接，如果写成c+=x相当于c=c+x，则进位会被拼接在后
            c = char(add % 2 + '0') + c;
            add /= 2;
        }
        return c;
    }
};
```