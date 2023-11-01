/*
題目：
https://leetcode.com/problems/insert-interval

解說：
耐心拆解

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l_pts = 0;
        int r_pts = 0;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(intervals[l_pts][0] <= newInterval[0]) l_pts++;
            if(intervals[r_pts][1] <= newInterval[1]) r_pts++;
        }
        
        for(int i = 0; i < l_pts-1; i++){
            ans.push_back(intervals[i]);
        }

        int new_left;
        if(l_pts == 0){
            new_left = newInterval[0];
        }else if(intervals[l_pts-1][1] < newInterval[0]){
            ans.push_back(intervals[l_pts-1]);
            new_left = newInterval[0];
        }else{
            new_left = intervals[l_pts-1][0];
        }

        if(r_pts >= n){
            ans.push_back({new_left, newInterval[1]});
        }else if(intervals[r_pts][0] <= newInterval[1]){
            ans.push_back({new_left, intervals[r_pts][1]});
        }else{
            ans.push_back({new_left, newInterval[1]});
            ans.push_back(intervals[r_pts]);
        }

        for(int i = r_pts+1; i < n; i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};