**题意：给一个上升数组，数组长度代表河上有多少个石头，每个元素表示这个石头所在的位置；初始青蛙在第一个石头上，而且第一跳只能跳一个单位；如果上一跳跳了k个单位，那么下一跳只能跳k-1、k或k+1个单位，而且青蛙只能向前跳，问青蛙能不能跳到最后一个石头上。**

**样例：**
```
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
```

<br/>
**TLE: dfs解，每次计算下一个位置和当前位置之间的间隔，如果这个间隔介于上一跳间隔k的k-1~k+1范围内，则跳到这个位置**

```
class Solution {
public:
    bool dfs(vector<int>& stones, int now, int k)
    {
        for(int i = now + 1; i < stones.size(); i++)
        {
            int gap = stones[i] - stones[now];
            if(gap < k - 1) continue;
            if(gap > k + 1) return false;
            if(dfs(stones, i, gap)) return true;//这儿不能直接return dfs()，因为可能满足在k-1~k+1之间的跳法有好几种，只要有一种可以到达最后一个石头就行
        }
        return now == stones.size()-1;//对于样例[0, 1, 3, 6, 10, 11, 12]，跳到10这个位置时就没法再向前跳了，出来for循环时就需要判断返回是否到达了最后一个石头
    }
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
};
```

<br/>
**AC解: 记忆化搜索，试了用数组存储就不对，map的find操作复杂度是O(logn)，unordered_map的count操作复杂度是O(1)**
```
/*
* pos最大是1100（最多有这么多个石头），那么最多能走到的位置是1+2+3+…＋1100也就是1100^2/2，
* 也就是k最大是1100（一步最多能走的单位数），1100需要11个二进制位表示，
* 那么同时表示pos和k就需要22个二进制位，也就是pos<<11 | k。
*/
class Solution {
public:
    unordered_map<int, bool> dp;
    bool dfs(vector<int> &stones, int pos, int k)
    {
        int key = pos | k << 11;
        if(dp.count(key) > 0) return dp[key];
        for(int i = pos+1; i < stones.size(); i++)
        {
            int gap = stones[i] - stones[pos];
            if(gap < k-1) continue;
            if(gap > k+1) return dp[key] = false;
            if(dfs(stones, i, gap)) return dp[key] = true;
        }
        return dp[key] = (pos == stones.size()-1);
    }
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
};
```