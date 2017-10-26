**题意：给一个非空数组包含非负整数，定义数组的degree为数组中元素出现最多的次数。找出子（连续）数组中有相同degree长度最小的子数组。**

**样例：**

```
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
```

<br/>

**需要注意的是对于有相同degree的子数组需要返回其中最短长度，只需记录每个distinct元素出现的初始位置和末尾位置即可。**

**map的key访问复杂度是O(logn)，因为本题中每个数字大小有上限，在10^6范围内，可以将map改为数组存储复杂度降到O(n)。**

```
struct Node{
    int cot;
    int start;
    int len;
    Node() {};
    Node(int cot, int start, int len): cot(cot), start(start), len(len) {};
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, Node> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])) {
                mp[nums[i]].cot++;
                mp[nums[i]].len = i - mp[nums[i]].start + 1;
            }else mp[nums[i]] = Node(1, i, 1);
        }
        map<int, Node>::iterator it;
        int _max = -1;
        int _len = 0x7fffffff;
        for(it = mp.begin(); it != mp.end(); it++){
            Node nd = it->second;
            if(nd.cot > _max || (nd.cot == _max && nd.len < _len)){
                _max = nd.cot;
                _len = nd.len;
            }
        }
        return _len;
    }
};
```