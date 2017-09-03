**题意：给一个字符串，找出其中回文子串的个数。起始索引或终止索引不同就算是不同的子串。**

**样例：**

```
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

<br/>

**和这个题5. Longest Palindromic Substring的做法一样，从中间开始枚举的时候记录。**

```
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        cot = n;
        for(int i = 1; i < n-1; i++){
            find(s, i-1, i+1);
        }
        for(int i = 0; i < n-1; i++){
            find(s, i, i+1);
        }
        return cot;
    }
private:
    int cot;
    void find(string &s, int l, int r){
        while(l < r && l >= 0 && r < s.size()){
            if(s[l] == s[r]){
                cot++;
                l--;
                r++;
            }else{
                return;
            }
        }
    }
};
```
