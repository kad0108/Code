**题意：给出文件的绝对路径，简化它。**

**样例：**

path = ```"/home/"```, => ```"/home"```

path = ```"/a/./b/../../c/"```, => ```"/c"```

path = ```"/home//foo/"```, => ```"/home/foo"```

path = ```"/../"```, => ```"/"```

<br/>
**参考discuss： 用getline和stringstream实现split方法，以```'/'```为切割**

```
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss, path, '/'))
        {
            if(path == "" || path == ".") continue;
            if(path == ".." && !stk.empty()) stk.pop_back();
            else if(path != "..") stk.push_back(path);
        }
        path = "";
        for(int i = 0; i < stk.size(); i++)
        {
            path += ('/' + stk[i]);
        }
        return stk.empty() ? "/" : path;
    }
};
```

**注意：**

1. ```"./"```表示当前目录，```"../"```表示上一级目录。
2. ```getline (stringstream& ss, string& str, char delim)``` 表示从流ss中提取字符并将其存储到str中，直到出现划分字符delim或者```'\n'```。例如ss中为```"/"```，那么str中读到的就是空字符```""```。