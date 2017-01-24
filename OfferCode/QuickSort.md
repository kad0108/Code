> 快速排序
> 对于一个区间，把第一个值作为key，partition的过程就是把比key小的放左边，比key大的放右边，然后递归求解左右区间。


**递归写法：一定注意l<r的条件**
```c++
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> num = {49, 38, 65, 67, 76, 13, 50};

int partition(int l, int r)
{
	int tmp = num[l];
	while(l < r)
	{
		while((l < r) && (tmp < num[r])) r--;
		if(l < r) num[l++] = num[r];
		while((l < r) && (tmp > num[l])) l++;
		if(l < r) num[r--] = num[l];
	}
	if(l >= r) num[l] = tmp;
	return l;
}

void quickSort(int l, int r)
{
	if(l < r)
	{
		int q = partition(l, r);
		quickSort(l, q-1);
		quickSort(q+1, r);
	}
}

int main()
{
	quickSort(0, num.size()-1);
	for(int i = 0; i < num.size(); i++) cout<<num[i]<<" ";
	cout<<endl;
    return 0;
}
```

**非递归写法：用栈模拟每次快排的区间**
```c++
struct Interval
{
	int l;
	int r;
};

int partition(int l, int r)
{
	int tmp = num[l];
	while(l < r)
	{
		while((l < r) && (tmp < num[r])) r--;
		if(l < r) num[l++] = num[r];
		while((l < r) && (tmp > num[l])) l++;
		if(l < r) num[r--] = num[l];
	}
	if(l >= r) num[l] = tmp;
	return l;
}

void quickSort()
{
	stack<Interval> stk;
	stk.push(Interval{0, int(num.size()-1)});
	while(!stk.empty())
	{
		Interval cur = stk.top();
		stk.pop();
		if(cur.l < cur.r)
		{
			int key = partition(cur.l, cur.r);
			stk.push(Interval{cur.l, key-1});
			stk.push(Interval{key+1, cur.r});	
		}else{
			break;
		}
	}
}
```

<br/>
**冒泡排序**
```c++
void bubble()
{
	for(int i = 0; i < num.size(); i++)
	{
		for(int j = 1; j < num.size(); j++)
		{
			if(num[j] < num[j-1]) swap(num[j], num[j-1]);
		}
	}
}
```
**实现O(n)的排序算法，辅助内存常量大小，排序应用环境为年龄**
```c++
void _sort(vector<int> num)
{
	vector<int> age(100, 0);//空间换时间
	for(int i = 0; i < num.size(); i++)
	{
		age[num[i]]++;
	}
	int idx = 0;
	for(int i = 0; i < age.size(); i++)
	{
		for(int j = 0; j < age[i]; j++)
		{
			num[idx++] = i;
		}
	}
	for(int i = 0; i < num.size(); i++) cout<<num[i]<<" ";
	cout<<endl;
}
```