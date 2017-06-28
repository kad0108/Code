**题意： 给一个数k，输出杨辉三角（帕斯卡三角）第k行， 比如`For example,given k = 3,Return [1,3,3,1].`**

<br/>

**wa： 直接求公式`C(n, m) = n! / (m! * (n-m)!)`，爆long long**

```
class Solution {
public:
    vector<int> getRow(int n) {
        tmp.clear();
        tmp.assign(n+1, 1);
        for(int i = 0; i <= n; i++){
            tmp.push_back(jiecheng(i));
        }
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(cnm(n, i));
        }
        return ans;
    }
private: 
    vector<long long> tmp;
    long long jiecheng(int k){
        if(k == 1 || k == 0) return tmp[k] = 1;
        if(tmp[k] != 1) return tmp[k];
        return tmp[k] = jiecheng(k-1) * k;
    }
    int cnm(int n, int m){
        return tmp[n] / (tmp[m] * tmp[n-m]);
    }
};
```

<br/>

**AC解： 递推公式`C(n, m) = C(n-1, m-1) + C(n-1, m)`，降维方法——滚动数组，原来很笨得去求第n行的每一个c(n,i)，实际上直接求C(n,n)第n行就是答案了**

```
class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            int id = i & 1;
            for(int j = 0; j <= i; j++){
                dp[id][j] = dp[id ^ 1][j-1] + dp[id ^ 1][j];
            }
        }
        return dp[n & 1];
    }
};
```

<br/>

**AC解： 继续降维，逆序推导**

```
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i; j >= 0; j--){
                if(j-1 >= 0) dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp;
    }
};
```