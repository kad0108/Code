**题意：比较两个版本号的大小，```v1<v2```返回-1，```v1>v2`返回1，相等返回0，版本号只包含数字和点。**

**样例：**
```
"01" = "1"
"1.0" = "1"
"1.0.1" < "1.1"
"1.2" < "1.10"
```

<br/>
**总之很多trick case，又一次用到了输入流来分割字符串。**
```
class Solution {
public:
    int getNum(string s)
    {
        int num = 0;
        for(int i = 0; i < s.size(); i++)
        {
            num = num*10 + (s[i]-'0');
        }
        return num;
    }
    vector<int> handle(string s)
    {
        stringstream ss(s);
        vector<int> v;
        while(getline(ss, s, '.'))
        {
            v.push_back(getNum(s));
        }
        while(v.back() == 0) v.pop_back();
        return v;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = handle(version1);
        vector<int> v2 = handle(version2);
        for(int i = 0; i < max(v1.size(), v2.size()); i++)
        {
            if(i >= v1.size()) return -1;
            if(i >= v2.size()) return 1;
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
```