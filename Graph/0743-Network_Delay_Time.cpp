/*
題目：
https://leetcode.com/problems/network-delay-time/

解說：
solution1 是利用 priority queue + BFS，time complexity 是 ElogE
在 priority queue 中放入的是從 k 到 node 的距離與 node {dist, node}
透過 priority queue 來自動排序取最小的，值到 priority queue 為空或是全部的 node 都被選取過了

solution2 典型的 Dijkstra 

有使用到的觀念：

*/

#include "../code_function.h"

typedef pair<int, int> PII;
class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> mp(n+1);

        for(auto t : times)
        {
            mp[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, k});
        vector<int> visited(n+1, 0);
        int ans = 0;

        while(!pq.empty())
        {
            auto [d, curr] = pq.top();
            pq.pop();

            if(visited[curr] == 1) continue;
            visited[curr] = 1;
            ans = max(ans, d);

            for(auto [next, weight] : mp[curr])
            {
                if(visited[next] == 1) continue;
                pq.push({d+weight, next});
            }
        }

        for(int i = 1; i <= n; i++)
            if(visited[i] == 0) return -1;
        return ans;
    }
};

class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> mp(n+1);

        for(auto t : times)
        {
            mp[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        vector<bool> seen(n+1, false);
        dist[k] = 0;

        for(int i = 1; i <= n; i++)
        {
            int minVal = INT_MAX;
            int minNode = -1;
            for(int j = 1; j <= n; j++)
            {
                if(!seen[j] && dist[j] < minVal)
                {
                    minVal = dist[j];
                    minNode = j;
                }
            }

            if(minNode == -1) break;
            seen[minNode] = true;

            for(auto [next, d] : mp[minNode])
                dist[next] = min(dist[next], dist[minNode] + d);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        return ans == INT_MAX ? -1 : ans;
    }
};