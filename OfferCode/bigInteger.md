**大整数加减法**

**两数相加可能会有一个数为负数**

```c++
string _plus(string &a, string &b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c(max(a.size(),b.size()), '0');
    int sum = 0;
    for(int i = 0; i < max(a.size(), b.size()); i++)
    {
        if(i < a.size()) sum += (a[i]-'0');
        if(i < b.size()) sum += (b[i]-'0');
        c[i] = sum % 10 + '0';
        sum /= 10;
    }
    if(sum) c.push_back(sum+'0');
    reverse(c.begin(), c.end());
    return c;
}

string _minus(string &a, string &b)//大数－小数
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c(max(a.size(), b.size()), '0');
    int num = 0;
    for(int i = 0; i < max(a.size(), b.size()); i++)
    {
        if(i < a.size()) num += (a[i]-'0');
        if(i < b.size()) 
        {
            if(a[i] < b[i]) num += 10;
            num -= (b[i]-'0');
        }
        c[i] = abs(num)  + '0';
        if(a[i] >= b[i]) num = 0;
        else num = -1;
    }
    //消去前缀0
    for(int i = c.size()-1; i >= 0; i--)
    {
        if(c[i] == '0') c.pop_back();
        else break;
    }
    if(!c.size()) c.push_back('0');
    reverse(c.begin(), c.end());
    return c;
}
```

<br/>
**大整数乘法**

```c++
string add(string a, string b){
    string c;
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    int num = 0;
    for(int i = 0; i < max(a.size(), b.size()); i++){
        if(i < a.size()) num += (a[i]-'0');
        if(i < b.size()) num += (b[i]-'0');
        c.push_back(num % 10 + '0');
        num /= 10;
    }
    if(num) c.push_back(num+'0');
    // reverse(c.begin(), c.end());
    return c;
}

string multiply(string a, string b){
    string c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int num = 0;
    string tmp;
    for(int j = 0; j < b.size(); j++){
        int digit = j;
        while(digit--) tmp.push_back('0');
        for(int i = 0; i < a.size(); i++){
            num += (a[i]-'0')*(b[j]-'0');
            tmp.push_back(num % 10 + '0');
            num /= 10;
        }
        if(num) {
            tmp.push_back(num+'0');
            num = 0;
        }
        c = add(c, tmp);
        tmp.clear();
    }
    reverse(c.begin(), c.end());
    return c;
}
```