**题意：给两个串s和t，问s是不是t的子串。子串一定是原串删掉一些字母且不改变其他字母顺序的新串。 (ie, "ace" is a subsequence of "abcde" while "aec" is not).**

**样例：**
```
s = "abc", t = "ahbgdc"  Return true.

s = "axc", t = "ahbgdc"  Return false.
```

<br/>
**遍历大串，当前位和小串相同就移动小串指针，最后判断小串指针是否移动到了串的末尾。**
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j]) i++;
        }
        return i == s.size();
    }
};
```