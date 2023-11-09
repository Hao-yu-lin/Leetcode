/*
題目：
https://leetcode.com/problems/jump-game-iii/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        const int n = arr.size();

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        int dir[2] = {-1, 1};

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int tmp = q.front();
                q.pop();
                if(arr[tmp] == 0) return true;
                visited[tmp] = true;
                for(int i = 0; i < 2; i++)
                {
                    int next = tmp + dir[i]*arr[tmp];
                    if(next < 0 || next >= n || visited[next] == true) continue;
                    q.push(next);
                }
            }
        }

        return false;
    }
};