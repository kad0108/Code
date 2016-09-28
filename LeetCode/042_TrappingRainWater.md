**题意：给一个数组，其中每个元素表示所在位置的高度，下雨之后能蓄多少水**

**样例：**
```
Given [0,1,0,2,1,0,1,3,2,1,2,1]

After the rain ,the volume of water traped is 6:
[0,1,1,2,2,2,2,3,2,2,2,1]
```

<br/>
**和二维的蓄水问题一样，都是从两侧向中间灌水，每次取两侧高度小的开始向一侧走，比如左侧l高度低，向右侧走到nextl，如果nextl高度低于l，则灌水并更新nextl的高度**

```
class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1;
        int ans = 0;
        while(l < r)
        {
            if(h[l] < h[r])
            {
                ans += max(h[l]-h[l+1], 0);
                h[l+1] = max(h[l+1], h[l]);
                l++;
            }
            else
            {
                ans += max(h[r]-h[r-1], 0);
                h[r-1] = max(h[r-1], h[r]);
                r--;
            }
        }
        return ans;
    }
};
```

<br/>
**系列问题：407. Trapping Rain Water II**

**类似问题：11. Container With Most Water**

**题意：给一个数组，每个元素表示每列的高度，找到两列和x轴围成的容器能装最多的水**

**如果h[l]<h[r]，那么能装的水取决于短的那一列，而且这时所有小于r的列围成的容器大小都不可能比r和l围成的容器大，那么l++；h[l]>h[r]同理。**
```
class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size()-1;
        int maxW = 0;
        while(l < r)
        {
            if(h[l] < h[r]) 
            {
                maxW = max(maxW, (r-l)*h[l]);
                l++;
            }
            else
            {
                maxW = max(maxW, (r-l)*h[r]);
                r--;
            }
        }
        return maxW;
    }
};
```