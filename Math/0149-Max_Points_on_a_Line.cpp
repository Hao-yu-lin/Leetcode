/*
題目：
https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

解說：


有使用到的觀念：

*/

#include "../code_function.h"

typedef struct Point{
    int x;
    int y;
    Point(vector<int>pt):x(pt[0]), y(pt[1]){};
}point_t;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; ++i){
            map<pair<int, int>, int> count;
            int same_pts = 1;
            int max_pts = 0;
            for(int j = i + 1; j < n; ++j){
                const Point& p1 = points[i];
                const Point& p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y) same_pts++;
                else{
                    max_pts = max(max_pts, ++count[getSlope(p1, p2)]);
                }
            }

            ans = max(ans, same_pts + max_pts); 
        }
        return ans;
    }
private:
    pair<int, int> getSlope(const Point& p1, const Point& p2){
        const int dx = p2.x - p1.x;
        const int dy = p2.y - p1.y;

        if(dy == 0) return {p1.y, 0};
        if(dx == 0) return {0, p1.x};

        const int d = gcd(dx, dy);
        return {dy/d, dx/d};
    }

    int gcd(int m, int n){
        return n == 0 ? m : gcd(n, m % n);
    }
};