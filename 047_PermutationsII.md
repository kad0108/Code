**题意: 给一个数组，元素有重复，给出所有唯一的排列组合。**

**样例：**
```
input: [1,1,2]
output: [
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```
<br/>
**解法一：根据剪枝思想，每次深搜时把要扩展的这个节点与同深度的上一个已扩展的节点值比较，如果相同则不扩展该节点。**

**开一个数组_record来维护上一次刚扩展完的每个深度的值，每次新扩展一个节点进行判断，如果要扩展就更新_record对应深度的值，同时把_record中大于此深度的数组值清空，否则就continue继续扩展同一深度的节点。**

```
const int inf = 0x7fffffff;
class Solution {
public:
    vector<int> nums;
    vector<int> v;
    vector<vector<int>> ans;
    bool mark[1005];

    int _record[1005];

    void _assign(int l, int r)
    {
        for(int i = l; i < r; i++)
        {
            _record[i] = inf;
        }
    }

    void dfs(int i)
    {
        if(i == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int j = 0; j < nums.size(); j++)
        {
            if(!mark[j])
            {
                if(_record[i] == inf) _record[i] = nums[j];
                else
                {
                    if(_record[i] == nums[j])
                    {
                        continue;//这儿不能直接return，因为同一层可能还有其他节点需要扩展
                    }
                    else
                    {
                        _record[i] = nums[j];
                        _assign(i + 1, nums.size());
                    }
                }
                v.push_back(nums[j]);
                mark[j] = 1;
                dfs(i + 1);
                v.pop_back();
                mark[j] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& n)
    {
        sort(n.begin(), n.end());
        nums = n;
        ans.clear();
        v.clear();
        memset(mark, 0, sizeof(mark));
        _assign(0, n.size());
        dfs(0);
        return ans;
    }
};
```
<br/>
**解法二：从输入数组开始，不停的求出它的nextPermutation直到nextPermutation等于输入排列**
```
class Solution{
public:
    void _swap(int &a, int &b)
    {
        int c = b;
        b = a;
        a = c;
    }
    vector<int> nextPermutation(vector<int>& nums)
    {
        int t = -1;//nums[t-1] < nums[t] > nums[t+1]
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                t = i;
                break;
            }
        }
        if(t == -1) t = 0;
        //找到的t右侧是递减的
        if(t == 0)
        {
            sort(nums.begin(), nums.end());
            return nums;
        }
        int s = t;//s > t && nums[s] 刚好> nums[t-1]
        for(int i = nums.size() - 1; i > t; i--)
        {
            if(nums[i] > nums[t - 1])
            {
                s = i;
                break;
            }
        }
        _swap(nums[s], nums[t - 1]);
        sort(nums.begin() + t, nums.end());
        return nums;
    }

    bool _equal(vector<int> &a, vector<int> &b)
    {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> start = nums;
        ans.push_back(nums);
        nums = nextPermutation(nums);
        while(!_equal(start, nums))
        {
            ans.push_back(nums);
            nums = nextPermutation(nums);
        }
        return ans;
    }
};
```