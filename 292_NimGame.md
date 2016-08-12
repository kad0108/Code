**题意：给n个石头，你和你的小伙伴每次只能轮流拿1～3个石头，谁拿走最后一个石头就胜利，你先开始拿。**

**样例：**
```
For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
```
<br/>
**TLE解法：思想是如果小伙伴赢，那么你肯定输了，所以判断```n-1、n-2、n-3```是否能赢。但递归层数太多。**

```
class Solution {
public:
    bool canWinNim(int n) {
        if(n == 1 || n == 2 || n == 3) return true;
        if(canWinNim(n - 1) && canWinNim(n - 2) && canWinNim(n - 3)) return false;
        return true;
    }
};
```
<br/>
**AC解法：参考discuss**

The base case: when n = 4, as suggested by the hint from the problem, no matter which number that that first player, the second player would always be able to pick the remaining number.

For 1* 4 < n < 2 * 4, (n = 5, 6, 7), the first player can reduce the initial number into 4 accordingly, which will leave the death number 4 to the second player. i.e. The numbers 5, 6, 7 are winning numbers for any player who got it first.

Now to the beginning of the next cycle, n = 8, no matter which number that the first player picks, it would always leave the winning numbers (5, 6, 7) to the second player. Therefore, 8 % 4 == 0, again is a death number.

Following the second case, for numbers between (2*4 = 8) and (3*4=12), which are 9, 10, 11, are winning numbers for the first player again, because the first player can always reduce the number into the death number 8.

So the solution could not be simpler!
```
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

