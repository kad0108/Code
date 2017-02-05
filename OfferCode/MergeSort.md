> 归并排序

> 每次将两个有序子数组合并，每次从两个数组中取最小的出来。

**递归写法**
```c++
class Solution{
public:
    void MergeSort(vector<int> &data){
        tmp.assign(data.size(), 0);
        _MergeSort(data, 0, data.size()-1);
    }
private:
    vector<int> tmp;
    void Merge(vector<int> &data, int l, int q, int r){
        int ll = l, lr = q;
        int rl = q+1, rr = r;
        int k = l;
        while((ll <= lr) && (rl <= rr)){
            if(data[ll] < data[rl]) tmp[k++] = data[ll++];
            else tmp[k++] = data[rl++];
        }
        while(ll <= lr) tmp[k++] = data[ll++];
        while(rl <= rr) tmp[k++] = data[rl++];
        for(int i = l; i <= r; i++){
            data[i] = tmp[i];
        }
    }
    void _MergeSort(vector<int> &data, int l, int r){
        if(l < r){
            int q = l + (r-l)/2;
            _MergeSort(data, l, q);
            _MergeSort(data, q+1, r);
            Merge(data, l, q, r);
        }
    }
};
```

<br/>

**非递归: 自底向上。从步长为1开始，相邻两个数两两merge，然后步长*2，继续合并两个子数组，直至两个子数组合并为整个数组。**
```c++
class Solution{
public:
    void MergeSort(vector<int> &data){
        int n = data.size()-1;
        tmp.assign(data.size(), 0);
        int step = 1;
        int idx;
        while(step < n+1){
            for(idx = 0; idx+step-1 <= n; idx += step*2){
                Merge(data, idx, idx+step-1, min(idx+2*step-1, n));
            }
            while(idx <= n){
                data[idx] = tmp[idx];
                idx++;
            }
            step *= 2;
        }
    }
private:
    vector<int> tmp;
    void Merge(vector<int> &data, int l, int q, int r){
        int ll = l, lr = q;
        int rl = q+1, rr = r;
        int k = l;
        while((ll <= lr) && (rl <= rr)){
            if(data[ll] < data[rl]) tmp[k++] = data[ll++];
            else tmp[k++] = data[rl++];
        }
        while(ll <= lr) tmp[k++] = data[ll++];
        while(rl <= rr) tmp[k++] = data[rl++];
        for(int i = l; i <= r; i++){
            data[i] = tmp[i];
        }
    }
};
```