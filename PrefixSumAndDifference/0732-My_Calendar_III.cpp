/*
題目：
https://leetcode.com/problems/my-calendar-iii/description/

解說：
使用差分數組(掃描線的用法)，針對數據上 start 進行 +1, end 進行 -1

有使用到的觀念：

*/

#include "../code_function.h"

class MyCalendarThree {
    map<int, int>mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) 
    {
        mp[startTime]++;
        mp[endTime]--;

        int ans = 0;
        int sum = 0;
        for(auto& [t, diff] : mp)
        {
            sum += diff;
            ans = max(ans, sum);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */