题目3 : Selling Antique Coins
时间限制:10000ms
单点时限:1000ms
内存限制:256MB


描述

```
You are the boss of an antique shop. You have N antique coins to sell. The i-th coin has Ai years of age and the selling price is Pi.

Today a VIP customer is coming to visit you and you won't let the chance slip! You know the customer has a specific habit. He will ask you to line up the coins from left to right and buy a coin if and only if it is older than the nearest R coins on its left and also older than the nearest R coins on its right. (If a coin has less than R coins on its left or right it should be older than them all.)

For example, if R=2 and you line up 4 coins from left to right which have 400 years, 100 years, 200 years and 300 years of age respectively, the customer will buy the 400-years coin and the 300-years coin.

You want to know how to line up the coins so that the total price of sold coins is maximized.
```

输入

```
The first line contains an integer T indicating the number of test cases.  

Each test case has three lines.  

The first line contains 2 integers N and R.

The second line contains N integers A1, A2, ... AN, the ages of the coins.

The third line contains N integers P1, P2, ... PN, the prices of the coins.

Note that older coins are not necessarily more expensive than newer coins.

For 30% of the data, 1 ≤ N ≤ 10  

For 60% of the data, 1 ≤ N ≤ 16

For 100% of the data, 1 ≤ T ≤ 10, 1 ≤ N ≤ 5000, 1 ≤ R ≤ N, 1 ≤ Ai ≤ 100000 (Ai are distinct), 1 ≤ Pi ≤ 100000
```

输出

```
For each test case output the maximum total sold price.
```

样例输入

```
1  
4 2  
100 200 300 400  
100 200 300 400
```

样例输出

```
700
```