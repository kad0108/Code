**题意：```'A'~'Z'```编码分别对应```1~26```，给一串数字编码串，要解码为字母，求出有几种解码方式。**

**样例：**
```
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
```

<br/>
**TLE解：DFS求出所有可能的解码情况。每一位都可以单独解码除了```'0'```，当某一位是```'1'或'2'```时，可以和下一位组合一起解码**

```
class Solution {
public:
    string tmp;
    int cot;
    void dfs(int i, string &s)
    {
        if(i == s.size())
        {
            // cout<<tmp<<endl;
            cot++;
            return;
        }
        if(s[i] != '0')
        {
            tmp.push_back(s[i]-'1'+'A');
            dfs(i+1, s);
            tmp.pop_back();
        }
        if(s[i] == '1' && i + 1 < s.size())
        {
            tmp.push_back((s[i]-'0')*10 + (s[i+1]-'0') + 'A' - 1);
            dfs(i+2, s);
            tmp.pop_back();
        }
        else if(s[i] == '2' && i+1 < s.size())
        {
            if(s[i+1] >= '0' && s[i+1] <= '6')
            {
                tmp.push_back((s[i]-'0')*10 + (s[i+1]-'0') + 'A' - 1);
                dfs(i+2, s);
                tmp.pop_back();
            }
        }
    }
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        cot = 0;
        tmp.clear();
        dfs(0, s);
        return cot;
    }
};
```

<br/>
**AC解：dp[i+1]表示以s[i]为结尾的编码串最多的解码方式，转移方式是有条件的，如果```s[i]!='0'```则dp[i+1]可以由dp[i]转移过来，也就是当前这位单独解析；如果s[i-1]s[i]这两位满足解码要求，则dp[i+1]还可以由dp[i-1]转移过来，也就是将这两位一起解析。这个dp状态需要s的长度大于1，dp[0]则只是个标志位用来单独处理dp[2]时情况。**
```
class Solution {
public:
    bool cal(char a, char b)
    {
        if(a == '0') return false;
        int num = (a-'0')*10 + (b-'0');
        if(num >= 10 && num <= 26) return true;
        else return false;
    }
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return s[0] != '0';
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] != '0');
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] != '0')
            {
                dp[i+1] += dp[i];
            }
            if(cal(s[i-1], s[i]))
            {
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }
};
```