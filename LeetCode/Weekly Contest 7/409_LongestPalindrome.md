**题意：给一个字符串由大小写字母组成，找出可以由这些字母组成的最长回文串。题目要求对大小写敏感，比如"Aa"不能被当作回文串。**

**样例：**
```
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
```

<br/>
**解：只需要计算出所有字母出现的次数，然后找出计数是奇数个的最多的放中间，偶数个的放两边，然后其他奇数个的选偶数个放两边。**
```
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cot(26*2, 0);
        int sum = 0;
        int maxodd = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z') cot[s[i]-'a']++;
            else cot[s[i]-'A' + 26]++;
        }
        int mark;
        for(int i = 0; i < cot.size(); i++)
        {
            if(cot[i] % 2)
            {
                if(cot[i] > maxodd)
                {
                    maxodd = cot[i];
                    mark = i;
                }
            }
        }
        sum += maxodd;
        for(int i = 0; i < cot.size(); i++)
        {
            if(cot[i] % 2) 
            {
                if(i != mark) sum += (cot[i]-1);
            }
            else sum += cot[i];
        }
        return sum;
    }
};
```