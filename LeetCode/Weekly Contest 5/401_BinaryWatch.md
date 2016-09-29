**题意：用四位二进制位表示小时(0~11)，用六位二进制为表示分钟(0~59)，现在给你二进制位为1的总个数，输出所有可能的小时分钟组合情况**

**样例：**
```
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
```

<br/>
**自己原来的想法是dfs求解，但是发现这样的话需要对二进制位进行排列组合，比如1个1和3个0进行排列组合，找出所有情况，但是这是个easy的题啊。。。应该不是这样做**

**AC解：遍历所有可能的小时和分钟，然后输出满足条件的组合**
```
class Solution {
public:
    int cot(int x)
    {
        int sum = 0;
        while(x)
        {
            if(x & 1) sum++;
            x >>= 1;
        }
        return sum;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h = 0; h <= 11; h++)
        {
            for(int m = 0; m <= 59; m++)
            {
                if(cot(h) + cot(m) == num)
                {
                    string tmp = to_string(m);
                    if(m < 10) tmp = '0' + tmp;
                    string s = to_string(h) + ':' + tmp;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
```