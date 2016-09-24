**题意：Gray Code(格雷码)是二进制位互不相同的一组数，给出非负整数n表示数字的二进制位的个数，要求生成greycode序列。**

**样例：**
```
given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
```

<br/>
**用dfs实现了一种序列，但是judge要求的生成序列没找到规律，参考discuss**
```
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        for(int i = 0; i < n; i++)
        {
            int size = ans.size();
            while(size)
            {
                size--;
                int num = ans[size];
                num += (1 << i);
                ans.push_back(num);
            }
        }
        return ans;
    }
};

/*dfs solution, the generate code sequence is not exactly the same as the judge*/
/*
class Solution {
public:
    int cal(vector<int> &a)
    {
        int ans = 0;
        int b = 1;
        for(int i = 0; i < a.size(); i++)
        {
            ans += a[i] * b;
            b <<= 1;
        }
        return ans;
    }
    vector<int> ans;
    vector<int> v;
    void dfs(int i, int n)
    {
        if(i == n)
        {
            ans.push_back(cal(v));
            return;
        }
        v.push_back(0);
        dfs(i+1, n);
        v.pop_back();
        v.push_back(1);
        dfs(i+1, n);
        v.pop_back();
    }
    vector<int> grayCode(int n) {
        ans.clear();
        v.clear();
        dfs(0, n);
        return ans;
    }
};
*/
```
