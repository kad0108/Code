**[题目链接](https://code.google.com/codejam/contest/6274486/dashboard#s=p1)**

<br/>
**Small dataset**

**暴力：小数据直接两层for循环枚举正方形起点，一个层for枚举正方形边长，另外两层for判断正方形是否合法。**

<br/>
**Large dataset**

**DP：dp[i][j]表示点(0,0)到点(i,j)所有合法的正方形个数，val[i][j]表示以(i,j)为右下角的正方形个数**
```
dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + val[i][j];

val[i-1][j-1]实际就是以(i-1, j-1)为右下角的正方形的最大边长。
val[i][j] = min(val[i-1][j-1], 以(i,j)为结尾的j列上最长合法边长, 以(i,j)为结尾的i列上最长合法边长);
```

**为降低复杂度需要先把每行每列的最长合法边长先算出来，_top和_left，用递归的方法计算，大数据n^3就跑不动了，需要注意如果点(i,j)位置上有怪兽，应该直接赋为0。**


```
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int t;
int r, c, k;
vector<vector<bool>> arr;
vector<vector<long long>> dp;
vector<vector<long long>> val;

vector<vector<long long>> _top;
vector<vector<long long>> _left;


int main()
{
    int tt = 1;
    cin>>t;
    while(tt <= t)
    {
        cin>>r>>c>>k;
        arr.assign(r, vector<bool>(c, 0));
        dp.assign(r, vector<long long>(c, 0));
        val.assign(r, vector<long long>(c, 0));
        _top.assign(r, vector<long long>(c, 0));
        _left.assign(r, vector<long long>(c, 0));
        
        for(int i = 0; i < k; i++)
        {
            int a, b;
            cin>>a>>b;
            arr[a][b] = 1;
        }
        //计算_top和_left
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                _left[i][j] = _top[i][j] = (arr[i][j] == 0);
                if(i > 0) _top[i][j] += _top[i-1][j];
                if(j > 0) _left[i][j] += _left[i][j-1];
                if(arr[i][j] == 1) 
                {
                    _top[i][j] = 0;
                    _left[i][j] = 0;
                }
            }
        }
        //先预处理第一行第一列
        dp[0][0] = arr[0][0] ? 0 : 1;
        val[0][0] = dp[0][0];
        for(int i = 1; i < r; i++)
        {
            dp[i][0] += dp[i-1][0];
            val[i][0] = min(min(_top[i][0], _left[i][0]), val[i-1][0] + 1);
            dp[i][0] += val[i][0];
        }
        for(int j = 1; j < c; j++)
        {
            dp[0][j] += dp[0][j-1];
            val[0][j] = min(min(_top[0][j], _left[0][j]), val[0][j-1]+1);
            dp[0][j] += val[0][j];
        }

        for(int i = 1; i < r; i++)
        {
            for(int j = 1; j < c; j++)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] += dp[i][j-1];
                dp[i][j] -= dp[i-1][j-1];
                if(arr[i][j] == 0)
                {
                    val[i][j] = min(min(_top[i][j], _left[i][j]), val[i-1][j-1]+1);
                    dp[i][j] += val[i][j];
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<dp[r-1][c-1]<<endl;
        tt++;
    }
    return 0;
}
```