**题意：给一个字符串s和一个整数k，找到最长子串t，t中每个字母都出现了至少k次。**

**样例：**
```
Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```

<br/>
**参考discuss：分治思想，用递归。首先用map记录字符串中每个字母出现了多少次；然后遍历一遍字符串找到第一个字母出现次数小于k次，这个字母是绝对不会出现在结果中的，然后以这个位置将字符串划分为左右两个部分；递归求解左右两个部分的最大长度。**
```
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size()) return 0;//不加这句k>s.size()会tle
        if(k == 0) return s.size();
        
        map<char, int> m;
        for(int i = 0; i < s.size(); i++)
        {
            if(m[s[i]]) m[s[i]]++;
            else m[s[i]] = 1;
        }
        int q = 0;
        while(q < s.size() && m[s[q]] >= k) q++;
        if(q == s.size()) return q;//如果这个串中每个字母出现次数都大于k，就返回串的长度
        
        int l = longestSubstring(s.substr(0, q), k);
        int r = longestSubstring(s.substr(q+1), k);//substr不加第二个参数表示截取从给定位置到串的末尾
        return max(l, r);
    }
};
```
