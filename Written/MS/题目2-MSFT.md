题目2 : MSFT
时间限制:10000ms
单点时限:1000ms
内存限制:256MB


描述

```
Little Ho has a string S consisting of only lowercase letters.

All letters in S are distinct except for 'm', 's', 'f' and 't'. Which means the four magical letters 'm', 's', 'f' and 't' can show up at most twice, while other letters can show up at most once.

Now little Ho wants to change S into T by swapping a pair of letters in S.

He wants to know the minimum amounts of such swaps he needs to do so.
```

输入

```
The first line contains an integer N, indicating the number of test cases.

Each test case contains two lines. The first contains the string S and the second contains the string T.

It is guaranteed that changing S into T is possible.

For 30% of the data, 1 ≤ length(S) == length(T) ≤ 10.

For 100% of the data, 1 ≤ N ≤ 10, 1 ≤ length(S) == length(T) ≤ 30.
```

输出

```
For each test case output the minimum amounts of swaps needed to turn S into T on a separate line.
```

样例输入
```
2
msra
asmr
fsmambfcs
mfsmbfcsa
```

样例输出
```
2
6
```