### 题意：给两个单词，找到从单词a变成单词b的最少操作数。只有三个操作被允许，插入一个字母、删除一个字母、替换一个字母。

**解法：经典dp，`dp[i][j]`表示单词a的0～i子串和单词b的0～j子串变成一样需要的最小花费。可以由三个状态转移过来，替换字母从`dp[i-1][j-1]`转移，删除字母从`dp[i-1][j]`和`dp[i][j-1]`转移，删除和插入字母相对应。**


注意：边界条件需要注意，子状态可能是空串会访问到数组下标位-1的位置的值，而`dp[i][-1]`和`dp[-1][j]`实际上都应该计算。所以非空串的计算应该从dp[1][1]算起较方便。

```
const int inf = 0x7fffffff;
class Solution {
public:
    int minDistance(string a, string b) {
        int lena = a.size(), lenb = b.size();
        if(!lena) return b.size();
        if(!lenb) return a.size();
        
        vector<vector<int>> dp(lena+1, vector<int>(lenb+1, 0));
        for(int i = 0; i <= lena; i++){
            for(int j = 0; j <= lenb; j++){
                if(i == 0 && j == 0) continue;
                dp[i][j] = inf;
                if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
                if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
        }
        return dp[lena][lenb];
    }
};
```

### 类似问题：583. Delete Operation for Two Strings，只有删除操作是允许的，与上一题思路一样，不同的是字母不一样时需要两个都删除。

```
class Solution {
public:
    int minDistance(string a, string b) {
        int lena = a.size(), lenb = b.size();
        if(!lena) return lenb;
        if(!lenb) return lena;
        const int inf = 0x7fffffff;
        vector<vector<int>> dp(lena+1, vector<int>(lenb+1, 0));
        for(int i = 0; i <= lena; i++){
            for(int j = 0; j <= lenb; j++){
                if(i == 0 && j == 0) continue;
                dp[i][j] = inf;
                if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 2));
                if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
        }
        return dp[lena][lenb];
    }
};
```