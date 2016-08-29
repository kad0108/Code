**题意: 求大整数乘法，要求不可以将string转为integer，也不可以使用biginteger。**

####有符号大整数运算的实现
```
class Solution {
public:
    int findIndex(int a[], int len)
    {
        for(int i = len; i >= 0; i--)
        {
            if(a[i] != 0) return i;
        }
        return 0;
    }
    void _swap(string &a, string &b)
    {
        string c = b;
        b = a;
        a = c;
    }
    string neg(string a)
    {
        string c(a.begin() + 1, a.end());
        return c;
    }
    /** 先实现无符号的加减法 **/
    string unsignedPlus(string a, string b)
    {
        int lena = a.size(), lenb = b.size();
        int add[1005];
        memset(add, 0, sizeof(add));
        for(int i = 0, j = 0; i < max(lena, lenb); i++, j++)
        {
            if(i >= lena) add[i] += (b[lenb - 1 - i] - '0');
            else if(i >= lenb) add[i] += (a[lena - 1 - i] - '0');
            else add[i] += (a[lena - 1 - i] - '0') + (b[lenb - 1 - i] - '0');
            add[i + 1] += (add[i] / 10);
            add[i] = add[i] % 10;
        }
        string ans;
        for(int i = findIndex(add, lena + lenb); i >= 0; i--)
        {
            ans.push_back(add[i] + '0');
        }
        return ans;
    }
    string unsignedMinus(string a, string b)
    {
        int lena = a.size(), lenb = b.size();
        int m[1005];
        memset(m, 0, sizeof(m));
        //judge whether a>b or a<b
        bool mark = true;
        if(lena < lenb)
        {
            mark = false;
            _swap(a, b);
        }
        else if(lena == lenb)
        {
            for(int i = 0; i < lena; i++)
            {
                if(a[i] == b[i]) continue;
                else if(a[i] > b[i]) break;
                else
                {
                    mark = false;
                    _swap(a, b);
                }
            }
        }
        //judge end
        lena = a.size();
        lenb = b.size();
        for(int i = 0; i < lena; i++)
        {
            int t1 = a[lena - 1 - i] - '0';
            if(i >= lenb) m[i] += t1;
            else
            {
                int t2 = b[lenb - 1 - i] - '0';
                if(t1 >= t2) m[i] += (t1 - t2);
                else
                {
                    m[i + 1] -= 1;
                    m[i] += (t1 + 10 - t2);
                }
            }
        }
        string ans;
        if(mark == false) ans.push_back('-');
        for(int i = findIndex(m, lena + lenb); i >= 0; i--)
        {
            ans.push_back(m[i] + '0');
        }
        return ans;
    }
    /** 实现有符号的加减乘除 **/
    string plus(string a, string b)
    {
        if(a[0] != '-' & b[0] != '-')//正 + 正
            return unsignedPlus(a, b);
        else if(a[0] != '-' && b[0] == '-')//正 + 负
            return unsignedMinus(a, neg(b));
        else if(a[0] == '-' && b[0] != '-')//负 + 正
            return unsignedMinus(b, neg(a));
        else if(a[0] =='-' && b[0] == '-')//负 + 负
            return '-'+unsignedPlus(neg(a), neg(b));
    }

    string minus(string a, string b)
    {
        if(a[0] != '-' & b[0] != '-')//正 - 正
            return unsignedMinus(a, b);
        else if(a[0] != '-' && b[0] == '-')//正 - 负
            return unsignedPlus(a, neg(b));
        else if(a[0] == '-' && b[0] != '-')//负 - 正
            return '-'+unsignedPlus(neg(a), b);
        else if(a[0] =='-' && b[0] == '-')//负 - 负
            return unsignedMinus(neg(b), neg(a));
    }

    string multiply(string a, string b)
    {
        int lena = a.size(), lenb = b.size();
        int mul[1005];
        memset(mul, 0, sizeof(mul));
        bool mark = true;
        if((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) mark = false;
        if(a[0] == '-') a = neg(a);
        if(b[0] == '-') b = neg(b);
        lena = a.size();
        lenb = b.size();
        for(int i = 0; i < lena; i++)
        {
            for(int j = 0; j < lenb; j++)
            {
                mul[i + j] += (a[lena - 1 - i] - '0') * (b[lenb - 1 - j] - '0');
                mul[i + j + 1] += (mul[i + j] / 10);
                mul[i + j] = (mul[i + j] % 10);
            }
        }
        string ans;
        if(mark == false) ans.push_back('-');
        for(int i = findIndex(mul, lena + lenb); i >= 0; i--)
        {
            ans.push_back(mul[i] + '0');
        }
        return ans;
    }
    string divide(string a, string b)
    {
        bool mark = true;
        if((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')) mark = false;
        if(a[0] == '-') a = neg(a);
        if(b[0] == '-') b = neg(b);
        string c(a.size(), '0');
        for(int i = 0; i < a.size(); i++)
        {

            for(int j = 1; j <= 9; j++)
            {
                c[i] = j + '0';
                string temp = multiply(c, b);
                //make '0'+a to compare with temp
                string temp_a;
                int len = a.size();
                while(len < temp.size())
                {
                    temp_a.push_back('0');
                    len++;
                }
                temp_a += a;
                if(temp > temp_a)
                {
                    c[i] -= 1;
                    break;
                }
            }
        }
        int k;
        for(k = 0; k < a.size(); k++)
        {
            if(c[k] != '0') break;
        }
        if(k == a.size()) k = a.size() - 1;
        string ans(c.begin() + k, c.end());
        if(mark == false) return '-' + ans;
        return ans;
    }
};
```
<br/>
####位运算实现int范围内的加减乘除
```
class Solution {
public:
    int add(int a, int b)
    {
        int mark = 0;
        //可能会溢出的两种情况：负+负，正+正
        if(a < 0 && b < 0) mark = -1;
        else if(a > 0 && b > 0) mark = 1;

        int temp = a;
        a = a ^ b;//不进位
        b = temp & b;//进位
        while(b != 0)
        {
            b <<= 1;
            if(mark == 1 && ((b >> 31) & 1) == 1) return INT_MAX;//判断进位最高位第32位是否为1
            else if(mark == -1 && b == 0) return INT_MIN;//当进位为0x80000000时左移1位变成0溢出
            temp = a;
            a = a ^ b;
            b = temp & b;
        }
        return a;
    }

    int minus(int a, int b)
    {
        b = add(~b, 1);// a - b = a + (-b)
        return add(a, b);
    }

    int multiply(int a, int b)
    {
        bool mark;
        if((a < 0 && b < 0) || (a > 0 && b > 0)) mark = true;
        else mark = false;
        if(a < 0) a = add(~a, 1);
        if(b < 0) b = add(~b, 1);

        int ans = 0;
        while(b)
        {
            if(b & 1) ans = add(ans, a);
            a <<= 1;
            b >>= 1;
        }
        if(mark) return ans;
        else return add(~ans, 1);
    }

    int divide(int a, int b) {
        //可能溢出的情况：除数为0， 或者INT_MIN / -1
        if(b == 0 || (a == INT_MIN && b == -1)) return INT_MAX;
        int cot = 0;
        bool mark;
        if((a < 0 && b < 0) || (a > 0 && b > 0)) mark = true;
        else mark = false;
        if(a < 0) a = add(~a, 1);
        if(b < 0) b = add(~b, 1);
        while(a >= b)
        {
            a = minus(a, b);
            cot = add(cot, 1);
        }
        if(mark) return cot;
        else return add(~cot, 1);
    }
};
```