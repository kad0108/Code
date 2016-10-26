**类似问题：168. Excel Sheet Column Title**

**题意直接看样例**
```
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
```

<br/>
规律是：ABCD = 26^3 * 1 + 26^2 * 2 + 26^1 * 3 + 26^0 * 4

主要需要处理的就是Z，％26得到的 和 /26得到的，对Z总是不适用
```
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n)
        {
            int tmp = (n-1) % 26;//得到0～25
            ans.push_back(tmp + 'A');
            n = (n-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

<br/>
**本题题意：直接看样例**
```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
```

<br/>

```
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += pow(26, n-i-1) * (s[i]-'A'+1);
        }
        return ans;
    }
};
```
