**题意：给一个数num，计算[0,num]范围内每个数字的二进制位为1的个数。**

**样例：**
```
For num = 5 you should return [0,1,1,2,1,2]
```

<br/>
**O(n*sizeof(integer))**
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        for(int i = 0; i <= num; i++)
        {
            int cot = 0, temp = i;
            while(temp)
            {
                if(temp & 1) cot++;
                temp >>= 1;
            }
            v.push_back(cot);
        }
        return v;
    }
};
```

<br/>
**Time complexity O(n) and Space complexity O(n)，有点dp的思想**
```
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return vector<int>(1, 0);
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for(int i = 2; i <= num; i++)
        {
            int cot = i & 1;
            v.push_back(v[i >> 1] + cot);
        }
        return v;
    }
};
```