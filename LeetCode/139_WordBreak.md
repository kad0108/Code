**题意：给一个字符串s和一个字典dict，问s是否能由dict中的单词组成。**

**样例：**
```
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
```

<br/>
**TLE解：用trie树+dfs做，每次都从根节点开始搜，碰到flag不为0就从这个位置分割开，继续dfs**
```
这个样例没有过：
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

```

倒是可以先处理一下，看是否s中有某个字母在dict中没有出现，但是这样做也不一定能ac

```
struct Tree
{
    int flag;
    int link[26];
    void init()
    {
        flag = 0;
        for(int i = 0; i < 26; i++)
        {
            link[i] = -1;
        }
    }
}trie[100005];

class Solution {
public:
    int id;
    void build(string s)
    {
        int top = 0;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(trie[top].link[s[i]-'a'] == -1)
            {
                trie[top].link[s[i]-'a'] = id;
                trie[id].init();
                id++;
            }
            top = trie[top].link[s[i]-'a'];
        }
        trie[top].flag++;
    }
    bool dfs(string s, int i)
    {
        if(i == s.size()) return true;
        int top = 0;
        while(1)
        {
            if(trie[top].link[s[i]-'a'] == -1) return false;
            top = trie[top].link[s[i]-'a'];
            i++;
            if(trie[top].flag)
            {
                if(dfs(s, i)) return true;//如果dfs返回false，还应该在当前路径继续向下找
            }
        }
    }
    void out(int top)
    {
        for(int i = 0; i < 26; i++)
        {
            int son = trie[top].link[i];
            if(son == -1) continue;
            cout<<trie[top].link[i]<<"-"<<char( i + 'a' )<<endl;
            out(son);
        }
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        id = 1;
        trie[0].init();
        unordered_set<string>::iterator it;
        for(it = wordDict.begin(); it != wordDict.end(); it++)
        {
            build(*it);
        }
        // out_dfs(0);
        return dfs(s, 0);
    }
};
```

<br/>
**AC解O(n^2 * d)：复杂度至少是n方，d是find操作的复杂度也就是元素间比较大小的复杂度。**

**dp[i]表示以i为结尾的串是否能有dict构成，dp[i]可以从所有```j=0~i-1```中dp[j]为true的状态转移过来，dp[j]为true，那么就看substr(j+1~i)是否能由dict构成。**
```
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<bool> dp(s.size(), 0);
        if(dict.find(string(1, s[0])) != dict.end()) dp[0] = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(dict.find(s.substr(0, i+1)) != dict.end())
            {
                dp[i] = true;
                continue;
            }
            for(int j = i-1; j >= 0; j--)
            {
                if(dp[j])
                {
                    string sub = s.substr(j+1, i-j);
                    if(dict.find(sub) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};
```

<br/>
**trie+dp解：O(n^2)至多n方，dp[i]已经算好，向后i+1~n转移，这时候去trie树上查找。**
```
struct Trie
{
    int flag;
    int link[26];
    void init()
    {
        flag = 0;
        for(int i = 0; i < 26; i++)
        {
            link[i] = -1;
        }
    }
}trie[100005];
class Solution {
public:
    int id;
    void build(string s)
    {
        int top = 0;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(trie[top].link[s[i]-'a'] == -1)
            {
                trie[top].link[s[i]-'a'] = id;
                trie[id].init();
                id++;
            }
            top = trie[top].link[s[i]-'a'];
        }
        trie[top].flag++;
    }
    void out(int top)
    {
        for(int i = 0; i < 26; i++)
        {
            int son = trie[top].link[i];
            if(son == -1) continue;
            cout<<son<<"-"<<char(i+'a')<<endl;
            out(son);
        }
    }
    bool wordBreak(string s, unordered_set<string>& dict) {
        id = 1;
        trie[0].init();
        unordered_set<string>::iterator it;
        for(it = dict.begin(); it != dict.end(); it++)
        {
            build(*it);
        }
        // out(0);
        int len = s.size(); 
        vector<bool> dp(len+1, 0);
        dp[0] = true;//root
        int top = 0;
        for(int i = 0; i <= len; i++)
        {
            if(!dp[i]) continue;
            int top = 0;
            for(int j = i+1; j <= len; j++)
            {
                int index = s[j-1]-'a';
                if(trie[top].link[index] == -1) break;
                top = trie[top].link[index];
                if(trie[top].flag) dp[j] = true;
            }
        }
        return dp.back();
    }
};
```