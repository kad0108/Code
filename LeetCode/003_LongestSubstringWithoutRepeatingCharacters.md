**题意：找出没有重复字母的最长子串**

**样例：**
```
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

<br/>
**需要两个指针维护当前没有重复字母的区域，l是做指针，遍历数组的i是右指针，并且开一个map纪录该区域内字母在数组中上一次出现的下标。因为每次find到s[i]时，并没有erase掉map[s[i]]，所以需要看找到的s[i]在不在l～i维护的区域内，在的话更新l和ans。不管哪种情况都需要更新map[s[i]]，下面代码是简化后的。**
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> mp;
        int l = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= l)
            {
                ans = max(ans, i-l);
                l = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
        ans = max(ans, n-l);
        return ans;
    }
};
```