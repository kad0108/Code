**题意：给出n和k，求n个数全排列的第k个排列。(1<= n <=9)**

**样例：**
```
n = 3, k = 3
1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
so the kth permutation sequence is "213".
```
<br/>
**TLE解法：dfs求出所有排列，找到第k个**
```
class Solution {
public:
    vector<string> v;
    string s;
    bool mark[1005];
    int N;
    void dfs(int i)
    {
        if(i == N)
        {
            v.push_back(s);
            return;
        }
        for(int j = 1; j <= N; j++)
        {
            if(!mark[j])
            {
                mark[j] = 1;
                s.push_back(j + '0');
                dfs(i + 1);
                mark[j] = 0;
                s.pop_back();
            }
        }
    }
    string getPermutation(int n, int k) {
        memset(mark, 0, sizeof(mark));
        v.clear();
        N = n;
        dfs(0);
        return v[k - 1];
    }
};
```
<br/>
**AC：O(n)参考discuss**

The pattern was that:

say n = 4, you have {1, 2, 3, 4}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)


We know how to calculate the number of permutations of n numbers... n! So each of those with permutations of 3 numbers means there are 6 possible permutations. Meaning there would be a total of 24 permutations in this particular one. So if you were to look for the (k = 14) 14th permutation, it would be in the

3 + (permutations of 1, 2, 4) subset.

To programmatically get that, you take k = 13 (subtract 1 because of things always starting at 0) and divide that by the 6 we got from the factorial, which would give you the index of the number you want. In the array {1, 2, 3, 4}, k/(n-1)! = 13/(4-1)! = 13/3! = 13/6 = 2. The array {1, 2, 3, 4} has a value of 3 at index 2. So the first number is a 3.

Then the problem repeats with less numbers.

The permutations of {1, 2, 4} would be:

1 + (permutations of 2, 4)

2 + (permutations of 1, 4)

4 + (permutations of 1, 2)

But our k is no longer the 14th, because in the previous step, we've already eliminated the 12 4-number permutations starting with 1 and 2. So you subtract 12 from k.. which gives you 1. Programmatically that would be...

k = k - (index from previous) * (n-1)! = k - 2*(n-1)! = 13 - 2*(3)! = 1

In this second step, permutations of 2 numbers has only 2 possibilities, meaning each of the three permutations listed above a has two possibilities, giving a total of 6. We're looking for the first one, so that would be in the 1 + (permutations of 2, 4) subset.

Meaning: index to get number from is k / (n - 2)! = 1 / (4-2)! = 1 / 2! = 0.. from {1, 2, 4}, index 0 is 1


so the numbers we have so far is 3, 1... and then repeating without explanations.


{2, 4}

k = k - (index from pervious) * (n-2)! = k - 0 * (n - 2)! = 1 - 0 = 1;

third number's index = k / (n - 3)! = 1 / (4-3)! = 1/ 1! = 1... from {2, 4}, index 1 has 4

Third number is 4


{2}

k = k - (index from pervious) * (n - 3)! = k - 1 * (4 - 3)! = 1 - 1 = 0;

third number's index = k / (n - 4)! = 0 / (4-4)! = 0/ 1 = 0... from {2}, index 0 has 2

Fourth number is 2


Giving us 3142.
```
class Solution {
public:
    int N;
    int fac(int n)
    {
        int sum = 1;
        for(int i = 1; i <= n; i++)
        {
            sum *= i;
        }
        return sum;
    }
    bool mark[15];
    int getNum(int index)
    {
        int i, cot = -1;
        for(i = 1; i <= N; i++)
        {

            if(!mark[i]) cot++;
            if(cot == index) break;
        }
        return i;
    }
    string getPermutation(int n, int k) {
        string s;
        k--;
        memset(mark, 0, sizeof(mark));
        N = n;
        while(1)
        {
            if(s.size() == N) break;
            int index = k / fac(n - 1);
            int num = getNum(index);
            s.push_back(num + '0');
            mark[num] = 1;
            k %= fac(n - 1);
            n--;
        }
        return s;
    }
};
```