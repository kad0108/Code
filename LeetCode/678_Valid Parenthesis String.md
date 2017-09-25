**题意：给一个字符串包含`(`、`)`和`*`，验证字符串是否合法。验证规则是：`(`右侧必须与`)`匹配，`*`可以认为是`(`、`)`或一个空串。**

**样例：**

```
Example 1:
Input: "(*)"
Output: True
Example 2:
Input: "(*))"
Output: True
```

<br/>

**发现好像得记录当前左括号右侧有多少个星号，当前右括号左侧有多少个星号，每次最近距离匹配消除这些状态都得更新，越写越麻烦。。。就直接看discuss了。**

**discuss是从左往右遍历记录左括号的上界和下界，遇到星号上界增加下界减少，遇到右括号上下界都减少，如果遍历过程中某次上界都小于0那么一定是不合法的，最后就看下界是否为0.**

```
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') low++, high++;
            else if(s[i] == ')') {
                if(low > 0) low--;
                high--;
            }else{
                if(low > 0) low--;
                high++;
            }
            if(high < 0) return false;
        }
        return low == 0;
    }
};
```
