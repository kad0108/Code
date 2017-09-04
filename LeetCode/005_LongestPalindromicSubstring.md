**题意：给出字符串的最长回文子串。**

<br/>

**TLE解法：O(n^3) 试探所有情况的两端位置向中间验证**

```
struct Node
{
    int l;
    int r;
    int len;
};
bool cmp(const Node &a, const Node &b)
{
    return a.len < b.len;
}
class Solution {
public:
    bool check(string s, int l, int r)
    {
        while(l <= r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int slen = s.length();
        if(slen <= 1) return s;
        vector<Node> v;
        v.clear();
        for(int i = 0; i < slen; i++)
        {
            for(int j = i + 1; j < slen; j++)
            {
                if(check(s, i, j))
                {
                    int len = j - i + 1;
                    v.push_back(Node{i, j, len});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        int index = v.size() - 1;
        string ans = s.substr(v[index].l, v[index].len);
        return ans;
    }
};
```
<br/>

**AC： O(n^2) 枚举回文串的中心位置**

```
class Solution {
public:
    int start, maxlen;
    void find(string &s, int l, int r)
    {
        while(l >= 0 && r < s.length())
        {
            if(s[l] == s[r])
            {
                if(r - l + 1 > maxlen)
                {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            else
            {
                return;
            }
        }
    }
    string longestPalindrome(string s)
    {
        int slen = s.length();
        if(slen <= 1) return s;
        //枚举回文串中心位置
        maxlen = 1;
        for(int i = 1; i < slen - 1; i++)//回文串长度为奇数
        {
            int l = i - 1;
            int r = i + 1;
            find(s, l, r);
        }
        for(int i = 0; i < slen - 1; i++)//回文串长度为偶数
        {
            int l = i;
            int r = i + 1;
            find(s, l, r);
        }
        string ans = s.substr(start, maxlen);
        return ans;
    }
};
```

**注意：**

1. 类中的成员变量start、maxlen不能初始化，语法规定。
2. find函数传入参数 void find(string s, int l, int r) 这种情况函数中进行运算的实参 s 是形参 string s 的副本。
所以 void find(string &s, int l, int r) 这种对字符串取地址的写法效率更高。
3. 原来的写法 借助vector存储 对于字符串"aaaaa......aaaaa" 生成的vector会很庞大，最后sort一下就不只是nlogn了。所以开全局的变量start记录最长回文子串的起始位置，maxlen最长子串长度。
4. 结构体中写函数。
```
struct Node
{
    int l;
    int r;
    int len() const
    {
        return r - l + 1;
    }
};
```

<br/>

**AC：Manacher算法 线性时间O(n)**

**教程：[马拉车算法](https://segmentfault.com/a/1190000003914228)**
```
class Solution {
public:
    int R[2100];
    string longestPalindrome(string s)
    {
        int size = 2 * s.size() + 1;
        string str;
        str.clear();
        //字符串预处理
        str.push_back('#');
        for(int i = 0; i < s.size(); i++)
        {
            str.push_back(s[i]);
            str.push_back('#');
        }
        //R数组记录i为中心的最长回文串半径
        for(int i = 0; i < size; i++) R[i] = 1;
        int maxRig = 0, pos = 0;
        int maxLen = 0, start = 0;
        for(int i = 0; i < size; i++)
        {
            //以i为中心扩展回文串
            if(i <= maxRig)
            {
                int j = 2 * pos - i;
                R[i] = min(R[j], maxRig - i);
            }
            while(i + R[i] < size && i - R[i] >= 0)
            {
                if(str[i + R[i]] == str[i - R[i]])
                {
                    R[i] += 1;
                }
                else
                {
                    break;
                }
            }
            //更新maxRig、pos
            if(i + R[i] > maxRig)
            {
                maxRig = i + R[i];
                pos = i;
            }
            //更新maxLen、start
            if(R[i] - 1 > maxLen)
            {
                maxLen = R[i] - 1;
                start = (i - maxLen)/2;//{[(i-R[i]+1)+1]-1}/2
            }
        }
        return s.substr(start, maxLen);
    }
};
```
**注意：**

1. R数组的大小。
2. i < maxRig时，利用已有匹配信息，无需再匹配，超出maxRig的部分继续匹配。！！匹配的是处理后的字符串str！！
3. 更新maxlen、start，利用原字符串索引与处理后字符串索引的关系。
