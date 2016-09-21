**题意：找出小于n的所有质数**

**[Hint](https://leetcode.com/problems/count-primes/)**

```
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n+1, true);
        for(int i = 2; i * i <= n; i++)
        {
            for(int j = i * i; j <= n; j += i)
            {
                p[j] = false;
            }
        }
        int cot = 0;
        for(int i = 2; i < n; i++)
        {
            if(p[i]) cot++;
        }
        return cot;
    }
};
```