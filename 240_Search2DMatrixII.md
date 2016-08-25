**题意：给一个矩阵，每行从左到右递增，每列从上到下递增，问一个数是否在这个矩阵中。**

<br/>
**AC解：根据矩阵特性，左上角的数值一定是最小，右下角数值一定最大。那么从右上角或者左下角开始寻找，对于右上角的数值 x ，如果```x > target```，那么x所在行可以排除，如果```x < target```，那么x所在列可以排除。左下角寻找同理。复杂度为O(m+n)。**

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i >= 0 && i < m && j >= 0 && j < n)
        {
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};
```
<br/>
**系列问题：74. Search a 2D Matrix**

**题意：给一个矩阵，每行从左到右递增，且每行的第一个数都大于上一行最后一个数，问一个数是否在这个矩阵中。**

<br/>
**AC解：看成是一个递增的数组，对整个矩阵的值的标号进行二分。**
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(matrix[mid / n][mid % n] == target) return true;
            if(matrix[mid / n][mid % n] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

```

