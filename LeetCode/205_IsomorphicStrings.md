**题意：判断两个字符串是不是同构的，即通过替换s中的字母可以得到t。要求不能有两个字母对应同一个字母。**

**样例：**
```
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
```

<br/>
**O(nlogn) 用map存替换的字母**
```
class Solution {
public:
    bool handler(map<char, char>& mp, string &s, string &t)
    {
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i]) return false;
            }else{
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        if(!handler(mp, s, t)) return false;
        mp.clear();
        if(!handler(mp, t, s)) return false;
        return true;
    }
};
```

<br/>
**O(n) 开两个数组记录之前同一位置对应的一对字母**
```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> a(128, -1), b(128, -1);
        for(int i = 0; i < s.size(); i++)
        {
            if(a[s[i]] != b[t[i]]) return false;
            a[s[i]] = i;
            b[t[i]] = i;
        }
        return true;
    }
};
```