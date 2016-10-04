**题意：给一个字典中包含很多个字符串，给一个目标串，找出目标串的简写串中长度最短的而且不是字典中任意一个字符串的简写。简写串中每个数字或字母的长度都为1，比如"a32bc"的长度是4。**

**样例：**

```
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
```

<br/>
**基于第一题做，对于目标串的每种简写都判断是否是字典中任意一个串的简写。生成目标串的简写，其实就是枚举2^n，n是目标串的长度，比如```"word", 1000```，表示简写是"w3"，为求解简便，将二进制位倒过来写，低位二进制位对应string起始位置。**

**数字转换成字符串to_string()的使用。string的push_back方法每次只能push一个字母，可以用append方法，也可以直接用＋进行字符串拼接。**

```
class Solution {
public:
    bool check(string target, string dic, int k)//判断target的简写k是不是dic的简写
    {
        if(target.size() != dic.size()) return false;//如果两个串size不一样，那么简写也一定不一样
        for(int i = 0; i < target.size(); i++)
        {
            if((k >> i) & 1)
            {
                if(target[i] != dic[i]) return false;
            }
        }
        return true;
    }
    string getAbbr(string target, int k)
    {
        string ans;
        int cot = 0;
        for(int i = 0; i < target.size(); i++)
        {
            if((k >> i) & 1)
            {
                if(cot)
                {
                    ans += to_string(cot);
                    cot = 0;
                }
                ans.push_back(target[i]);
            }
            else
            {
                cot++;
            }
        }
        if(cot) ans += to_string(cot);
        return ans;
    }
    string minAbbreviation(string target, vector<string>& dics) {
        if(dics.size() == 0) return to_string(target.size());//对于字典为空的情况，不加这句会tle
        
        int m = target.size();
        string ans;
        for(int k = 0; k < (1 << m); k++)//枚举2^m，1表示要这一位的字母，0表示不要
        {
            bool mark = false;//判断字典中是不是有串的简写和target简写一样
            for(int i = 0; i < dics.size(); i++)
            {
                if(check(target, dics[i], k))
                {
                    mark = true;
                    break;
                }
            }
            if(!mark)
            {
                string tmp = getAbbr(target, k);
                if(ans.empty() || tmp.size() < ans.size()) ans = tmp;
            }
        }
        return ans;
    }
};
```