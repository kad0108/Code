**题意：给出没有重叠的区间集合，插入一个新的区间，如果有重叠进行合并。**

**系列题目56. Merge Intervals**

**样例：**
```
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]
```

**直接调用上一题的函数，对区间集合按区间的start排序，先处理前两个区间，然后从处理好的区间集合中拿出末尾区间和未处理区间比较。注意：区间可能会有大区间包含小区间。**

```
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& v) {
        if(v.empty() || v.size() == 1) return v;
        vector<Interval> ans;
        sort(v.begin(), v.end(), cmp);
        if(v[0].end >= v[1].start) ans.push_back(Interval(v[0].start, max(v[0].end, v[1].end)));
        else
        {
            ans.push_back(v[0]);
            ans.push_back(v[1]);
        }
        for(int i = 2; i < v.size(); i++)
        {
            Interval tmp = ans.back();
            if(tmp.end >= v[i].start)
            {
                ans.pop_back();
                ans.push_back(Interval(tmp.start, max(tmp.end, v[i].end)));
            }
            else
            {
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> ans = merge(intervals);
        return ans;
    }
};
```
