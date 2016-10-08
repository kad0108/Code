**题意：给一个编码串，返回对应的解码串。编码规则是k[encoded_string]表示中括号内的encoded_string重复k次，出现的数字仅仅是k，不会出现像2[4]这种情况。**

**样例：**
```
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
```

<br/>
**用string模拟栈，遍历输入编码串，碰到数字就放入vector中，碰到'['或字母压入栈中，碰到']'，就弹栈直到碰到'['，将弹出的子串记录到tmp中，然后vector中末尾的数字就是这个tmp串要重复的次数，将生成的重复串再压入栈中。**
```
class Solution {
public:
    string decodeString(string s) {
        string ans;
        vector<int> num;
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(sum) sum = sum*10 + (s[i]-'0');
                else sum = (s[i]-'0');
            }
            else if(s[i] == '[')
            {
                num.push_back(sum);
                sum = 0;
                ans.push_back(s[i]);
            }
            else if(s[i] == ']')
            {
                string tmp;
                while(ans.back() != '[')
                {
                    tmp.push_back(ans.back());
                    ans.pop_back();
                }
                if(ans.back() == '[') ans.pop_back();
                int cot = num.back();
                num.pop_back();
                string rep;
                while(cot--) rep += tmp;
                while(!rep.empty())
                {
                    ans.push_back(rep.back());
                    rep.pop_back();
                }
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
```