/*
題目：
https://leetcode.com/problems/remove-adjacent-almost-equal-characters/

解說：
從 index 0 開始連續兩兩看
根據定義
Two characters a and b are almost-equal if a == b or a and b are adjacent in the alphabet.
因此可以寫成 abs(word[i]-word[i+1]) <= 1，若已經替換過，因此將該字替換成 '*'，避免後面使用它

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int removeAlmostEqualCharacters(string word) 
    {
        int ans = 0;
        for(int i = 0; i < word.length()-1; i++)
        {
            if(word[i] == '*') continue;
            int w1 = word[i] - 'a';
            int w2 = word[i+1] - 'a';
            if(abs(w1-w2) <= 1){
                ans++;
                word[i] = '*';
                word[i+1] = '*';
            }
        }
        
        return ans;
    }
};