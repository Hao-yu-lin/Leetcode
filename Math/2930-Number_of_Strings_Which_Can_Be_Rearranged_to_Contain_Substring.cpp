/*
題目：
https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/

解說：
使用排容原理，全部 - 不可能的組合
不可能組合
C1 = 0 L
C2 = 0 T
C3 = 0 E
C4 = 1 E
不可能組合 = C1 + C2 + C3 + C4 
            - C1&C2 - C1&C3 - C1&C4 - C2&C3 - C2&C4 - C3&C4 
            + C1&C2&C3 + C1&C2&C4 + C1&C3&C4 + C2&C3&C4
            - C1&C2&C3&c4
因為 C3&C4 == 0 -> C1 + C2 + C3 + C4 
                - C1&C2 - C1&C3 - C1&C4 - C2&C3 - C2&C4 
                + C1&C2&C3 + C1&C2&C4


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
private:
    int powerMod(int x, int n, int mod) {
        int result = 1, p = x % mod;
        while (n) {
            if (n & 1) {
                result = (1LL * result * p) % mod;
            }
            p = (1LL * p * p) % mod;
            n >>= 1;
        }
        return result;
    }
    
public:
    int stringCount(int n) {
        int count = 0, mod = 1e9 + 7;
        count = (count + powerMod(26, n, mod)) % mod;
        count = (count - (n + 75LL) * powerMod(25, n - 1, mod)) % mod;
        count = (count + (2LL * n + 72) * powerMod(24, n - 1, mod)) % mod;
        count = (count - (n + 23LL) * powerMod(23, n - 1, mod)) % mod;
        return (count % mod + mod) % mod;
    }
};