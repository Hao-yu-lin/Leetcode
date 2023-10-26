/*
題目：
https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/

解說：
解題觀念在
假設要分類為 x 組, x+1組。
a = count/(x+1) , b = count%(x+1)
如果 b == 0 則代表可以剛好分成 a 個 x+1組別
若 b != 0， x-b 的意涵代表著將還差 x-b 個就可以湊成 x 個
此時如果 x-b <= a 時，代表我們可以從 a 群中個別抽一個湊成一組新的 size 為 x 的組
若 x-b > a 則代表無法分割成 x 組與 x+1 組

有使用到的觀念：
Array, Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> ump;
        const int n = nums.size();
        
        for(const auto& k : nums)
        {
            ump[k]++;
        }
        

        vector<int> count_vec;
        for(const auto& p : ump)
        {
            count_vec.push_back(p.second);
        }
        
        sort(count_vec.begin(), count_vec.end());
        int ans = INT_MAX;
        for(int i = 1; i <= count_vec[0]; i++)
        {
            int tmp = isvalid(i, count_vec);
            if(tmp != -1)
                ans = min(ans, tmp);
        }
        if(ans == INT_MAX) return -1;
        else return ans;         
    }

    int isvalid(int x, vector<int>& count_vec)
    {
        int total = 0;
        for(const auto& c : count_vec)
        {
            int a = c/(x+1);
            int b = c%(x+1);

            if(b == 0)total += a;
            else if((x-b) <= a){
                total += (a+1);
            }else return -1;

        }

        return total;
    }
};
