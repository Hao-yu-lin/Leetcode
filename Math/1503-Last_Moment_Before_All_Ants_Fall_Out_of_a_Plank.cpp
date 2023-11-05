/*
題目：
https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

解說：
兩隻螞蟻碰撞後會改變方向，若將兩隻螞蟻不做標記，則碰撞後仍然有螞蟻向左與向右移動。
因此只需在乎最左邊的螞蟻抵達端點，與最右邊的螞蟻抵達端點，哪一側花的時間最久。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int t1 = left.size() == 0 ? 0 : left.back() - 0;
        int t2 = right.size() == 0 ? 0 : n - right[0];

        return max(t1, t2);    
    }
};
