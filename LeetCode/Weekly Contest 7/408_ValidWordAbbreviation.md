**题意：给一个字符串word，和一个简写字符串abbr，问abbr是不是word的简写。**

```
word的简写写法有：

1ord w1rd wo1d wor1 2rd w2d wo2 w3 3d 1o1d w1r1 2r1 1o2 4
```

<br>
**这个题赛后变成收费的了，只能根据回忆尽可能还原题意及样例了。**

```
class Solution{
public:
    bool validWordAbbreviation(string word, string abbr){
        int k = 0;
        int num = 0;
        bool mark = true;
        for(int i = 0; i < abbr.size(); i++)
        {
            if(abbr[i] >= '0' && abbr[i] <= '9')
            {
                if(abbr[i] == '0' && num == 0)//对于"a","01"这个样例，前导0是不符合的，应该返回false
                {
                    mark = false;
                    break;
                }
                num = num * 10 + (abbr[i] - '0');
            }
            else
            {
                if(num)
                {
                    k += num;
                    num = 0;
                }
                if(abbr[i] != word[k++])//不管num是不是0都需要比较当前对应位是否相同
                {
                    mark = false;
                    break;
                }
            }
        }
        if(num)//abbr最后一位是数字时还应该判断是否可以匹配对应word中相同个数的字母，比如样例"abbe","a4"应该返回false
        {
            string tmp = word.substr(k, word.size()-k);
            if(tmp.size() != num) mark = false;
        }
        return mark;
    }
};
```