**题意：给一个非负整数的数组，将它们排列组成最大的数，这个数可能会很大。**

**样例：**
```
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
```

<br/>
**自己本来想的是对所有数按位排序，最高位大的放前面，这一位相同的看下一位，比如[3, 30, 34]这几个数，最高位3相同看下一位，没有下一位的就把下一位用上一位的值，即[33, 30, 34]，把3的下一位也看作3，这样来比较。**

**知道了正解，应该是返回字符串比较结果```a+b > b+a```，比如[3, 30]，a+b＝"330"，b+a＝"303"，所以3应该排在30的前面。注意前导0。**
```
bool cmp(int &a, int &b)
{
    string aa = to_string(a);
    string bb = to_string(b);
    return aa + bb > bb + aa;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return string();
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for(int i = 0; i < nums.size(); i++)
        {
            string tmp = to_string(nums[i]);
            if(ans.empty() && tmp == "0") continue;
            ans += tmp;
        }
        if(ans.empty()) ans = "0";
        return ans;
    }
};
```