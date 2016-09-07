**题意：n皇后问题，在n*n的棋盘上无冲突摆放n个棋子，任意一个皇后所在位置的同行、同列、以及45度角都不能出现其他皇后棋子。**


**最开始以为是两个主对角线不冲突**

```
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> s;
    bool judge(int r, int c, int n)
    {
        //因为dfs每次行递增，所以只需要判断这一列是否冲突
        for(int i = 0; i < n; i++)
        {
            if(s[i][c] == 'Q') return false;
        }
        //因为dfs每次行递增，所以只需要判断左上45度，而不需要判断右下45度
        for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(s[i][j] == 'Q') return false;
        }
        //只需要判断右上45度
        for(int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
        {
            if(s[i][j] == 'Q') return false;
        }
        return true;
    }
    void dfs(int i, int n)
    {
        if(i == n)
        {
            ans.push_back(s);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(judge(i, j, n))
            {
                s[i][j] = 'Q';
                dfs(i + 1, n);
                s[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        s.clear();
        s.assign(n, string(n, '.'));
        dfs(0, n);
        return ans;
    }
};
```
<br/>
**解法二：自己本来也想到了开一个标记数组，但是对角线标记解决不了，看到discuss里面很trick的解法**

The number of columns is n, the number of left-top 45° diagonals is ```2 * n - 1```, the number of right-top 45° diagonals is also ```2 * n - 1```. 

When reach [row, col], the column No. is col, the right-top 45° diagonal No. is ```row + col``` and the left-top 45° diagonal No. is ```n - 1 + col - row```. 
```
class Solution {
public:
    vector<bool> visC, visl, visr;
    vector<vector<string>> ans;
    vector<string> s;
    void dfs(int i, int n)
    {
        if(i == n)
        {
            ans.push_back(s);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(!visC[j] && !visl[i+j] && !visr[n-1+j-i])
            {
                visC[j] = visl[i+j] = visr[n-1+j-i] = 1;
                s[i][j] = 'Q';
                dfs(i + 1, n);
                s[i][j] = '.';
                visC[j] = visl[i+j] = visr[n-1+j-i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        s.clear();
        s.assign(n, string(n, '.'));
        visC.assign(n, 0);
        visl.assign(2*n-1, 0);
        visr.assign(2*n-1, 0);
        dfs(0, n);
        return ans;
    }
};
```