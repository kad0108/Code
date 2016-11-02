**题意：求n的阶乘末尾有多少个0**

<br/>
**发现2和5相乘会得到一个0，那么看n之前有多少个数有包含2或5这两个因数，包含因数2的数的数量一定大于包含因数5的，那么就只看n之前有多少个数包含因数5，特别地对于25、125这类数只由5相乘得到也要将所有因数5的个数算入。**
```
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n)
        {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
```