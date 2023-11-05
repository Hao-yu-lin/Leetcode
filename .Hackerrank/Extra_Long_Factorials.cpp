/*
題目：
https://www.hackerrank.com/challenges/extra-long-factorials/problem

解說：
將每一位數都存在陣列，因此要計算該位數時，將該位數提取出來，進行乘積與加上前一位數的進位數

有使用到的觀念：
Math
*/

#include "../code_function.h"

void extraLongFactorials(int n) {
    vector<int> digit;
    int m = 1; // digit counter;
    digit.push_back(1);
    
    int carry = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x = digit[j]*i + carry;
            digit[j] = x % 10;
            carry = x/10;
        }
        while(carry > 0)
        {
            digit.push_back(carry%10);
            carry = carry/10;
            m++;
        }
    }
    
    for(int i = m-1; i >= 0; i--)
    {
        cout << digit[i];
    }
}