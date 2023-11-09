/*
題目：
https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff = abs(sx - fx), ydiff = abs(sy - fy);
        if(xdiff == 0 && ydiff == 0 && t == 1) return false;
        return (min(xdiff, ydiff) + abs(xdiff - ydiff)) <= t;
    }
};