**题意：给一个32位的无符号整数，反转二进制位**

**样例：**
```
given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).
```

<br/>
**最一般的想法就是开个数组存所有的二进制位然后reverse数组，但这样的空间复杂度是O(n)。可以只开一个变量来降低空间复杂度，注意是32个二进制位。**
```
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int cot = 0;
        while(n)
        {
            if(n & 1) ans = ans * 2 + 1;
            else ans *= 2;
            n >>= 1;
            cot++;
        }
        while(cot < 32)
        {
            ans *= 2;
            cot++;
        }
        return ans;
    }
};
```