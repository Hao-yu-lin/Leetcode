/*
題目：
https://leetcode.com/problems/happy-number/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = cal_happy(n);
        }
        return n==1;
    }

    int cal_happy(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
};