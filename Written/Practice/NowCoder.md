> 题目描述

> 给两个字符串(可能包含空格)，找出其中最长公共连续子串，并输出其长度，输入两串长度均小于50.

两层for循环枚举其中一个串的所有子串，然后和另一个串进行匹配，小串和大串匹配用kmp。

```
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int N = 55;

int _next[N];
string s1, s2;

void getNext(string s)
{
    _next[0] = -1;
    int j = 0;
    int k = -1;
    while(j < int(s.size()))
    {
        if(k == -1 || s[j] == s[k])
        {
            _next[++j] = ++k;
        }
        else
        {
            k = _next[k];
        }
    }
}

bool kmp(string s1, string s2)
{
    int i = 0, j = 0;
    while(i < s1.size() && j < int(s2.size())) // 注意j会是负数，所以一定将s2.size()转换为int类型再比较
    {
        if(j == -1 || s1[i] == s2[j]) i++, j++;
        else j = _next[j];
    }
    if(j == int(s2.size())) return true;
    return false;
}

int main(){
    //freopen("in.txt", "r", stdin);
    getline(cin, s1); // 输入字符串可能包含空格
    getline(cin, s2);
    int mx = 0;
    for(int p = 0; p < s2.size(); p++)
    {
        for(int q = p; q < s2.size(); q++)
        {
            string tmp(s2.begin()+p, s2.begin()+q+1);
            getNext(tmp);
            if(kmp(s1, tmp)) mx = max(mx, int(tmp.size()));
        }
    }
    cout<<mx<<endl;
    return 0;
}
```