> 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
> 输出需要删除的字符个数。

输入描述:

> 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.


输出描述:

> 对于每组数据，输出一个整数，代表最少需要删除的字符个数。

输入例子:
> abcda
> google

输出例子:
> 2
> 2
>

解法一：直接dp
```c++
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int N = 1009;
int dp[N][N]; // dp[i][j]表示从i~j删除最少的字符，使得剩下的回文串最长
string s;


int dfs(int i, int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = 0;
    if(j - i == 1)
    {
        if(s[i] == s[j]) return dp[i][j] = 0;
        return dp[i][j] = 1;
    }
    int d = 0x7fffffff;
    if(s[i] == s[j]) d = min(d, dfs(i+1, j-1));
    d = min(d, dfs(i, j-1)+1);
    d = min(d, dfs(i+1, j)+1);
    return dp[i][j] = d;
}

int main()
{
    freopen("in.txt", "r", stdin);
    while(cin>>s)
    {
        memset(dp, -1, sizeof(dp));
        cout<<dfs(0, s.size()-1)<<endl;
    }
    return 0;
}
```
解法二：将问题转化成求原串和逆串的最长公共子序列，然后需要删除的字符就是两串的长度减去最长公共子序列
```c++
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1009;
int dp[N][N];// dp[i][j]表示原串0~i和逆串0~j的最长公共子序列
string s;

int main()
{
    freopen("in.txt", "r", stdin);
    while(cin>>s)
    {
        memset(dp, 0, sizeof(dp));
        string re = s;
        reverse(re.begin(), re.end());
        dp[0][0] = (s[0] == re[0]);
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                int tmp = 0;
                if(i - 1 >= 0 && j - 1 >= 0) tmp = dp[i-1][j-1];
                dp[i][j] = max(dp[i][j], tmp + (s[i] == re[j]));
            }

        }
        cout<<len-dp[len-1][len-1]<<endl;
    }
    return 0;
}
```

