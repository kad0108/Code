**系列题目：224. Basic Calculator**

**题意：计算表达式，只包含```'(', ')', '-', '+', ' '```和非负整数，表达式一定合法**

<br/>
**原来还想着加减符号优先级一样，不管括号直接计算的，```2-(5-6)```这种情况的样例就说明这种想法不对了。**

**看了discuss的解法，栈用来存左括号前的计算结果result和符号sign，每次计算好一组括号内的结果，就和左括号前的计算结果整合，因为加减法的优先级一样，所以除括号外的计算顺序无所谓。**
```
class Solution {
public:
    int calculate(string s) {
        int num = 0; //记录遇到符号前的上一个数字
        int res = 0; //记录遍历到当前位之前的结果
        int sign = 1; //记录上一个符号正负
        stack<int> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + (s[i]-'0');
            }
            else if(s[i] == '+')
            {
                res += sign * num;
                sign = 1;
                num = 0;
            }
            else if(s[i] == '-')
            {
                res += sign * num;
                sign = -1;
                num = 0;
            }
            else if(s[i] == '(')
            {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                res += sign * num;
                num = 0;
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
```

<br/>
**本题题意：表达式包含非负整数、加减乘除符号和空格。**

**回忆了一下后缀表达式的概念，一个数值栈一个符号栈，符号栈内需要维护栈顶到栈底的符号优先级递减，每次符号入栈都需要保证当前栈顶的符号优先级小于这个符号，不然就弹栈，每次符号栈弹一次栈，数值栈都要弹两次栈，再将计算结果push到数值栈中。**
```
class Solution {
public:
    int pro(char sign)// priority
    {
        switch(sign)
        {
            case '+':
                return 1;
            case '-':
                return 1;
            case '*':
                return 2;
            case '/':
                return 2;
        }
        return 0;
    }
    int operate(int a, int b, char sign)
    {
        int ans = 0;
        switch(sign){
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                ans = a / b;
                break;
        }
        return ans;
    }
    int calculate(string s) {
        stack<int> stk1;
        stack<char> stk2;
        int num = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9') num = num*10 + (s[i]-'0');
            else 
            {
                stk1.push(num);
                num = 0;
                while(!stk2.empty() && (pro(s[i]) <= pro(stk2.top())))
                {
                    char sign = stk2.top();
                    stk2.pop();
                    int b = stk1.top();
                    stk1.pop();
                    int a = stk1.top();
                    stk1.pop();
                    stk1.push(operate(a, b, sign));
                }
                stk2.push(s[i]);
            }
        }
        stk1.push(num);
        while(!stk2.empty())
        {
            char sign = stk2.top();
            stk2.pop();
            int b = stk1.top();
            stk1.pop();
            int a = stk1.top();
            stk1.pop();
            stk1.push(operate(a, b, sign));
        }
        return stk1.top();
    }
};
```