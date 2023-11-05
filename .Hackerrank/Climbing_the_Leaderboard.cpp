/*
題目：
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

解說：
這裡讓我卡最久的地方是在，如何將 ranked 的實際排名給呈現出來，後來使用 unique 與 erase 達成
std::unique 會將連續重複的數字給刪除，最後回傳一個 iteration，該 iteration 之後都不是原本儲存的資料
因此透過 erase 方式從該位置往後刪除到最後

有使用到的觀念：
Binary Search
*/

#include "../code_function.h"

inline int findrank(const vector<int>& ranked, int score)
{
    int left = 0;
    int right = ranked.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(ranked[mid] == score) return mid+1;
        else if(ranked[mid] > score) left = mid+1;
        else right = mid-1;
    }
    
    return left+1;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) 
{
    ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());
    vector<int> ans;
    for(int i = 0; i < player.size(); i++)
    {
        ans.push_back(findrank(ranked, player[i]));
    }
    return ans;
}