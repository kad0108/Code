**[题目链接](https://code.google.com/codejam/contest/6274486/dashboard#s=p0)**

<br/>
**Large dataset**

**需要注意的就是不管这个位置有没有monster attractor，只要在这个位置没有抓到怪兽，之后再访问这个位置时，概率都是```(1-p)^vis```，其中p是位置本身的概率，vis是这个位置被访问的次数，再次访问这个位置抓到怪兽的概率应该是前几次访问都没有抓到怪兽。**

**还有就是字符矩阵输入时，注意到字符与字符之间是有空格的，如果是用getline读取一整行，需要按空格分割，这时应该要先初始化stringstream。**
```
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


int t;
int r, c, rs, cs, step;
double p, q;
vector<string> map;
vector<vector<int>> vis;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
double ans;

bool bound(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

void dfs(int i, int j, int st, double maxp)
{
    if(st == step)
    {
        ans = max(ans, maxp);
        return;
    }
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k], ny = j + dy[k];
        if(bound(nx, ny))
        {
            double tmp;
            if(vis[nx][ny])
            {
                if(map[nx][ny] == 'A')
                {
                    tmp = maxp + pow(1-p, vis[nx][ny])*p;
                }
                else tmp = maxp + pow(1-q, vis[nx][ny])*q;
            }
            else
            {
                if(map[nx][ny] == 'A') tmp = maxp + p;
                else tmp = maxp + q;
            }
            vis[nx][ny]++;
            dfs(nx, ny, st+1, tmp);
            vis[nx][ny]--;
        }
    }
}

int main()
{
    freopen("D://A-large-practice.in", "r", stdin);
    freopen("D://out.txt", "w", stdout);
    cin>>t;
    int tt = 1;
    while(tt <= t)
    {
        cin>>r>>c>>rs>>cs>>step;
        cin>>p>>q;
        vis.assign(r, vector<int>(c, 0));
        map.clear();
        getchar();
        for(int i = 0; i < r; i++)
        {
            string s;
            for(int j = 0; j < c; j++)
            {
                char ch;
                cin>>ch;
                s.push_back(ch);
            }
            map.push_back(s);
        }
        ans = 1e-12;
        dfs(rs, cs, 0, 0);
        printf("Case #%d: %.7f\n", tt, ans);
        tt++;
    }
    return 0;
}
```