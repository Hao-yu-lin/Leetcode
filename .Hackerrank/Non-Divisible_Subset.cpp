/*
題目：
https://www.hackerrank.com/challenges/non-divisible-subset/problem

解說：
將全部的數字取 module k 後，開始個別考慮
任兩數相加不能被 k 整除
%k = 0 的可以取一個
如果 i != k-i 時(1%4, 3%4)：%k = i 與 %k = k-i 只能擇其一，否則這兩個集合相加會 == k
如果 i == k-i 代表取兩個以上的 count[i] 會使得相加被 k 整除，因此只能取一個

有使用到的觀念：

*/

#include "../code_function.h"

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> count(k, 0);
    for(const auto&c : s)
    {
        count[c%k] ++;
    }
    
    int ans = 0;
    if(count[0] > 0) ans++;
    for(int i = 1; i < (k/2+1); i++)
    {
        if(i != k-i){
            ans += max(count[i], count[k-i]);
        }else ans++;
    }
    
    return ans;
}