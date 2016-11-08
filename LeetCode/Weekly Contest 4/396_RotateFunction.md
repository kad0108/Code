**题意：给一个数组A长度为n，Bk表示把A顺时针旋转k位，定义F函数为：```F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]```，计算F的最大值**

**样例：**
```
A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
```

<br/>
**TLE: 暴力O(n^2)**
```
class Solution {
public:
    void rotate(vector<int> &arr, int k)
    {
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
    int maxRotateFunction(vector<int>& arr) {
        if(arr.size() == 0) return 0;
        int maxSum = -0x7fffffff - 1;
        for(int i = 0; i < arr.size(); i++)
        {
            rotate(arr, 1);
            int sum = 0;
            for(int j = 0; j < arr.size(); j++)
            {
                sum += j * arr[j];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
```

<br/>
**AC：找规律O(n)**
```
f[0] = 0*A[0] + 1*A[1] + ... + (n-1)A[n-1];
f[1] = 0*A[n-1] + 1*A[0] + 1*A[2] + ... + (n-1)A[n-2]
f[2] = ...

f[1] - f[0] = (A[0] + A[1] + ... + A[n-2]) - (n-1)A[n-1] 
			= (A[0] + A[1] + ... + A[n-1]) - nA[n-1]
...
归纳得：
f[k] - f[k-1] = sum(A[0]~A[n-1]) - nA[n-k]
```

```
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        long long sum = 0;
        vector<long long> f(n, 0);
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            f[0] += i * A[i];
        }
        int maxSum = f[0];
        for(int k = 1; k < n; k++)
        {
            f[k] = f[k-1] + sum - n*A[n-k];
            maxSum = max(maxSum, (int)f[k]);
        }
        return maxSum;
    }
};
```