**题意：一个很大的数字以字符串形式输入，移除k位使得新的数最小**

**样例：**
```
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

<br/>
**自己原来的想法是，从左到右遍历数字字符串，前一个比后一个大就移除前一个否则push到一个新的字符串中，之后再单独处理一下k!=0和新字符串中有前导0的情况。但是对于```"234561" k=2```这种类型的样例过不了。**

**AC解：参考discuss，用string模拟栈的使用，每次如果栈顶元素比当前遍历到的元素大，就一直pop直到栈顶元素小于当前遍历元素，将当前元素push，避免前导0的写法很赞。**
```
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(int i = 0; i < num.size(); i++)
        {
            while(!ans.empty() && ans.back() > num[i] && k)
            {
                ans.pop_back();
                k--;
            }
            if(!ans.empty() || num[i] != '0') ans.push_back(num[i]);
        }
        while(ans.size() && k--) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};
```