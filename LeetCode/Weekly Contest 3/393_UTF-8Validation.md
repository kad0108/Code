**题意：给一个数组，问数组中数的二进制表示是不是一个合法的utf-8编码。**

[Reference](https://www.zhihu.com/question/23374078)

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.

For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

So the UTF-8 binary sequence are:

0xxxxxxx

110xxxxx 10xxxxxx

1110xxxx 10xxxxxx 10xxxxxx

11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

**样例：**
```
Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

<br/>
**题目说了UTF-8编码长度是1~4字节，所以分别判断这几种情况即可。**
```
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cot = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if(cot == 0)
            {
                if((data[i]>>3) == 0b11110) cot = 3;//4字节
                else if((data[i]>>4) == 0b1110) cot = 2;//3字节
                else if((data[i]>>5) == 0b110) cot = 1;//2字节
                else if((data[i]>>7) == 0b1) return false;//1字节 开头应该是0
            }
            else
            {
                if((data[i]>>6) == 0b10) cot--;
                else return false;
            }
        }
        return cot==0;
    }
};
```