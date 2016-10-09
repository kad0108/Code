**题意：实现大整数加法**

<br/>
**比赛时写的代码，太长了。。。主要注意两个串对应为求和时应该把结果串中的进位也加上。**
```
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size(), m = num2.size();
        string ans(max(n, m)+1, '0');
        int num, i;
        for(i = 0; i < n && i < m; i++)
        {
            num = (num1[i]-'0') + (num2[i]-'0') + (ans[i]-'0');
            ans[i] = num%10 + '0';
            ans[i+1] = (ans[i+1]-'0') + num/10 + '0';
        }
        while(i < n)
        {
            num = (ans[i]-'0') + (num1[i]-'0');
            ans[i] = num%10 + '0';
            ans[i+1] = num/10 +'0';
            i++;
        }
        while(i < m)
        {
            num = (ans[i]-'0') + (num2[i]-'0');
            ans[i] = num%10 + '0';
            ans[i+1] = num/10 +'0';
            i++;
        }
        
        while(!ans.empty() && ans.back() == '0') ans.pop_back();
        if(ans.empty()) ans.push_back('0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

<br/>
**简洁的写法，这种写法结果串不会有前导0**
```
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int num = 0;
        string ans(max(n, m), '0');
        for(int i = 0; i < max(n, m); i++)
        {
            if(i < n) num += (num1[i]-'0');
            if(i < m) num += (num2[i]-'0');
            ans[i] = num%10 + '0';
            num /= 10;
        }
        if(num) ans.push_back(num+'0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```