题目4 : Unimodal Permutation
时间限制:10000ms
单点时限:1000ms
内存限制:256MB



描述

```
P is permutation of {1, 2, ... N}. Each time you can move one number to the leftmost position.

For example, moving number 3 will change {1, 2, 3, 4, 5} into {3, 1, 2, 4, 5}.

Your goal is to change P = {P1, P2, ... PN} into a unimodal permutation which means for some value k (1 ≤ k ≤ N), {P1, P2, ... Pk} is monotonically increasing and {Pk, Pk+1, ... PN} is monotonically decreasing.  

What is the least possible number of moves?
```

输入

```
The first line contains an integer N.

The next line contains N integers P1, P2, ... PN.

For 20% of the data, 1 ≤ N ≤ 10  

For 40% of the data, 1 ≤ N ≤ 20

For 100% of the data, 1 ≤ N ≤ 1000, {P1, P2, ... PN} is a permutation of {1 .. N}.  
```

输出

```
The least possible number of moves.
```


样例输入

```
5  
4 3 1 5 2
```

样例输出

```
2
```