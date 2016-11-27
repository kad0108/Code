**题意：给一个字符串s和一个字典dict，求s能由dict组成的各种情况。**

**样例:**
```
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
```

<br/>
**TLE：dp+dfs，求dp时把每一位能从哪几个位置转移过来用vector记录下来，然后dfs求解所有情况。**
```
例如：能从起始位置转移过来的标为-1
0 1 2  3 4 5 6 7 8 9
c a t  s a n d d o g
   -1 -1     3     6
             2

TLE样例：
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```
```
struct Node
{
    bool mark;
    vector<int> pre;
    Node(){}
};
class Solution {
public:
    vector<string> ans;
    void dfs(string s, int index, vector<Node> &dp, string str)
    {
        if(index == -1) 
        {
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int i = 0; i < dp[index].pre.size(); i++)
        {
            int tmp = dp[index].pre[i];
            dfs(s, tmp, dp, s.substr(tmp+1, index-tmp) + " " + str);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        int len = s.size();
        vector<Node> dp(len, Node());
        if(dict.find(string(1, s[0])) != dict.end())
        {
            dp[0].mark = true;
            dp[0].pre.push_back(-1);
        }
        for(int i = 1; i < len; i++)
        {
            if(dict.find(s.substr(0, i+1)) != dict.end())
            {
                dp[i].mark = true;
                dp[i].pre.push_back(-1);
            }
            for(int j = i-1; j >= 0; j--)
            {
                if(dp[j].mark)
                {
                    string sub = s.substr(j+1, i-j);
                    if(dict.find(sub) != dict.end())
                    {
                        dp[i].mark = true;
                        dp[i].pre.push_back(j);
                    }
                }
            }
        }
        dfs(s, len-1, dp, "");
        return ans;
    }
};
```

<br/>
**AC：参考discuss，dfs+记忆化，函数wordBreak返回s由dict组成的结果，遍历s，以i划分s，如果后缀单词在dict中存在，则前缀由dict组成的结果与后缀拼接。**
```
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    
    vector<string> combine(vector<string> prev, string post)
    {
        for(int i = 0; i < prev.size(); i++)
        {
            prev[i] += " " + post;
        }
        return prev;
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(mp.count(s)) return mp[s];
        vector<string> res;
        if(dict.count(s)) res.push_back(s);
        for(int i = 1; i < s.size(); i++)
        {
            string post = s.substr(i);
            if(dict.count(post))
            {
                string pre = s.substr(0, i);
                vector<string> tmp = combine(wordBreak(pre, dict), post);
                res.insert(res.end(), tmp.begin(), tmp.end());//从res的末尾插入tmp
            }
        }
        mp[s] = res;
        return res;
    }
};
```