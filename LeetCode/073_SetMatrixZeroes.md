**样例：给一个矩阵，如果某个元素为0，就把它的整行整列都置为0。减少额外空间的使用**

<br/>
**注意第一行第一列要单独处理，因为如果统一处理，matrix[0][0]这个位置是0的话，那么第一行就都会被赋为0，覆盖了记录的信息。**
```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr = false, fc = false;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0) fr = true;
                    if(j == 0) fc = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(fr)
        {
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
        if(fc)
        {
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
    }
};
```