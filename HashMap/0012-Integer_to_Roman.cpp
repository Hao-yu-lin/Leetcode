/*
題目：
https://leetcode.com/problems/integer-to-roman/

解說:
暴力解，因為 num 只有到 3999 因此可以使用暴力解的方式，將所有可能的羅馬字母組合列出來

有使用到的觀念：
Hash Map
*/

#include "../code_function.h"

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};