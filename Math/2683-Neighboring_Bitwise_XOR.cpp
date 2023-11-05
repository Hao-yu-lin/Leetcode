/*
題目：
https://leetcode.com/problems/neighboring-bitwise-xor

解說：
solution1：
因為 derived[i] = original[i] xor original[i + 1]
因此可以透過 original[i + 1] = original[i] xor derived[i]
根據 xor 性質，若存在合法的 orig 數列，orig[0] = orig[0] ^ derived[0] ^ derived[1] ^ .... ^ derived[n-1]
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1
1 ^ 1 = 0

solution 1 是比賽時，想到的解法
solution 2 是網路上大神的寫法

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        const int n = derived.size();
        vector<int> orig(n, 0);

        orig[0] = 0;
        for(int j = 1; j < n; j++)
        {
            orig[j] = derived[j-1] ^ orig[j-1];
        }
        if((orig[0] ^ orig[n-1] )== derived[n-1]) return true;
        
        
        return false;
    }
};

class Solution2 {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int i = 0;
        for(auto& d : derived)
        {
            i ^= d;
        }

        return i == 0;
    }
};
