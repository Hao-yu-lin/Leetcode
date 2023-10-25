/*
題目：
https://leetcode.com/problems/k-th-symbol-in-grammar/

解說：
Row N-1     0   1
Row N       01  10
由前一個 parent 為何推論出，下一層是屬於 01 還是 10

有使用到的觀念：
Recursion
*/

#include "../code_function.h"

class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        if(n == 1) return 0;
        int parent = kthGrammar(n-1, k/2 + k%2); // 2 -> 1, 3 -> 2
        int isodd = k%2;
        if(parent == 1) return isodd ? 1 : 0; // 1 -> 10 
        else return isodd ? 0 : 1;      // 0 -> 01
    }
};