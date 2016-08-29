**题意: 给一个n*m的矩阵，以螺旋形式输出。以及给整数n，生成对应的螺旋矩阵。**

**样例：**
```
input: [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
output: [1,2,3,6,9,8,7,4,5]

input: n=3
output: [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```
<br/>
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if(n == 0) return vector<int>();
        int m = matrix[0].size();

        int li = 0, ri = n - 1, lj = 0, rj = m - 1;
        while(li <= ri && lj <= rj)
        {
            int i = li, j = lj;
            for(;j <= rj; j++) ans.push_back(matrix[i][j]);
            if(ans.size() == n * m) break;
            for(j--, i++; i <= ri; i++) ans.push_back(matrix[i][j]);
            for(i--, j--; j >= lj; j--) ans.push_back(matrix[i][j]);
            if(ans.size() == n * m) break;
            for(j++, i--; i > li; i--) ans.push_back(matrix[i][j]);
            li++;
            lj++;
            rj--;
            ri--;
        }
        return ans;
    }

    vector<vector<int>> generateMatrix(int n, int m) {
        vector<vector<int>> ans;
        int num = 1;
        int li = 0, ri = n - 1, lj = 0, rj = m - 1;
        ans.assign(n, vector<int>());
        for(int k = 0; k < n; k++) ans[k].assign(m, 0);
        while(li <= ri && lj <= rj)
        {
            int i = li, j = lj;
            for(; j <= rj; j++) ans[i][j] = num++;
            if(num > n * m) break;//发现螺旋结束的位置一般是j变化的两个方向
            for(j--, i++; i <= ri; i++) ans[i][j] = num++;
            for(i--, j--; j >= lj; j--) ans[i][j] = num++;
            if(num > n * m) break;
            for(j++, i--; i > li; i--) ans[i][j] = num++;
            li++;
            lj++;
            ri--;
            rj--;

        }
        return ans;
    }
};
```