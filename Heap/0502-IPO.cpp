/*
題目：
https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

解說：


有使用到的觀念：
Heap
*/

#include "../code_function.h"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // {capital, profits}
        vector<pair<int, int>> tasks;
        for(int i = 0; i < profits.size(); i++)
        {
            tasks.push_back({capital[i], profits[i]});
        }

        sort(tasks.begin(), tasks.end());
        priority_queue<int> pq;

        int count = 0;
        int curr = 0;

        while(count < k)
        {
            while(curr < tasks.size() && tasks[curr].first <= w)
            {
                pq.push(tasks[curr].second);
                curr++;
            }
            if(pq.empty()) break;

            w+=pq.top();
            pq.pop();
            count++;
        }

        return w;
    }
};