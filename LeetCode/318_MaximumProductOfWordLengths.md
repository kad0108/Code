**题意：给一个单词数组，要求返回最大的两单词长度之和，而且两单词不能有相同的字母。输入均为小写字母，如果不存在这样的两个单词，返回0。**

**样例：**
```
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
```

<br/>
**直接暴力写TLE了，没想到怎么降低复杂度，参考discuss。用一个数的二进制位替代数组来记录每个单词中出现了哪些字母。**

```
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0 || n == 1) return 0;
        vector<int> digit(n, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                digit[i] |= (1 << (words[i][j]-'a'));//不能用+=因为会有重复的字母，这里只关心有哪些字母出现
            }
        }
        int maxl = 0;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(!(digit[i] & digit[j]))
                {
                    int tmp = words[i].size() * words[j].size();
                    maxl = max(maxl, tmp);
                }
            }
        }
        return maxl;
    }
};
```
