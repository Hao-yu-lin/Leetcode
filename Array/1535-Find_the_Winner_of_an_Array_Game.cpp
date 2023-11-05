/*
題目：
https://leetcode.com/problems/find-the-winner-of-an-array-game/

解說：
使用 queue 來自動排隊比較，若 k > arr.size() 則當比較 arr.size() 後 winner 會是該 arr 的最大值
此時輸出最大值即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int n = arr.size();

        queue<int> q;
        int winner = arr[0];
        for(int i = 1; i < n; i++)
        {
            q.push(arr[i]);
        }
        int win_count = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp = q.front();
            q.pop();
            if(winner > tmp)
            {
                win_count ++;
                q.push(tmp);
            }else
            {
                win_count = 1;
                q.push(winner);
                winner = tmp;
            }
            if(win_count == k) return winner;
        }

        return winner;
    }
};