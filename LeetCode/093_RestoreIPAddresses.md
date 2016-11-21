**题意：输入只包含数字的字符串，输出所有合法的ip地址组合。**

**样例：**
```
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
```

<br/>
**dfs解，ip地址每一位范围是0~255，，每一位的划分长度最长为3。**

**注意：**

1.需要判断id+i是否超出了字符串长度，不然会RE。
2.str放在函数外就需要有pop，所以作为函数的参数会方便些。str的修改也不应该在for循环里，应该在传参时。
3.stoi实现string转integer。
4.提交发现的问题，ip每一位的地址不能有前导0。

```
class Solution {
public:
    vector<string> ans;
    void dfs(string s, int cot, int id, string str)
    {
        if(cot > 4) return;
        if(cot == 4 && id == s.size()) 
        {
            ans.push_back(str);
            return;
        }
        for(int i = 1; i < 4 && id+i <= s.size(); i++)
        {
            string sub = s.substr(id, i);
            if(stoi(sub) > 255) continue;
            if(sub.size() > 1 && sub[0] == '0') continue;
            dfs(s, cot+1, id+i, (cot == 3) ? str+sub : str+sub+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        dfs(s, 0, 0, "");
        return ans;
    }
};
```