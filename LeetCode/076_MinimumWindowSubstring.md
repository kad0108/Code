### 题意：给两个字符串s和t，在s中找到最小的窗口能够包含t中所有的字符，没有返回空串。

题意中没有描述清楚的地方：字符串中包含所有字符，并不仅仅是大小写字母，而且重复字符的个数也需要考虑。

#### 解法：用两个指针最开始指向s串起始位置，看两个指针维护的区间是否包含t中所有的字符，不是则右指针右移，否则左指针右移。原来以为只有大写字母，就用一个int型整数的二进制形式表示有哪个字母，看看是不是`sbin & tbin == tbin`。但是不仅仅有大小写字母，就用数组来记录每个字符出现了多少次，再开个变量表示当前满足了t串中多少个字符。

```
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vt(200, 0);
        vector<int> vs(200, 0);
        int tcot = 0; // 记录t串中有多少个不同的字符
        for(int i = 0; i < t.size(); i++){
            if(vt[t[i]] == 0) tcot++;
            vt[t[i]]++;
        }
        const int inf = 0x7fffffff;
        int start = 0, len = inf, scot = 0;
        for(int l = 0, r = 0; l <= r; ){
            if(scot == tcot){
                if(r-l < len) start = l, len = r-l; // 最初进来这个条件，r已经在上一次++操作了，所以窗口长度不是r-l+1
                int ch = s[l];
                vs[ch]--;
                if(vs[ch] < vt[ch]) scot--; // l和r维护的窗口内字符个数<t串中对应字符个数，s串中满足t串的字符个数才需要-1
                l++;
            }else{
                if(r >= s.size()) break; // 这个条件如果放在for语句中，找到第一个满足条件的窗口就不会再找了
                int ch = s[r];
                vs[ch]++;
                if(vs[ch] == vt[ch]) scot++;
                r++;
            }
        }
        if(len != inf) return s.substr(start, len); // 没有找到这样的窗口时len还是inf
        return "";
    }
};
```