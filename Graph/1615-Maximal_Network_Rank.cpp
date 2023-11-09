/*
題目：
https://leetcode.com/problems/maximal-network-rank/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> mp(n, vector<int> (n));
        
        vector<int> countRoads(n, 0);

        for(auto r : roads){
            int p1 = r[0];
            int p2 = r[1];

            countRoads[p1] ++;
            countRoads[p2] ++;

            mp[p1][p2] = 1;
            mp[p2][p1] = 1;
        }

        int maxRank = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int currRank = countRoads[i] + countRoads[j] - mp[i][j];

                maxRank = max(maxRank, currRank);
            }
        }

        return maxRank;
    }
};