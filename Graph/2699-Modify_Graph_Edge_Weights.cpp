/*
題目：
https://leetcode.com/problems/modify-graph-edge-weights/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

using PII = pair<int, int>;
class Solution {
    unordered_map<int, int> next[105];
    int todo[105][105];
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) 
    {
        for(auto& e : edges)
        {
            int a = e[0], b = e[1], weight = e[2];
            if(weight == -1)
            {
                weight = 1;
                todo[a][b] = 1;
                todo[b][a] = 1;
            }
            
            next[a][b] = weight;
            next[b][a] = weight;
        }

        priority_queue<PII, vector<PII>, greater<>> pq;
        
        // backpropagation
        vector<int> dist_back(n, INT_MAX/3);
        pq.push({0, destination});

        while(!pq.empty())
        {
            auto [d, curr] = pq.top();
            pq.pop();
            if(dist_back[curr] != INT_MAX/3) continue;
            dist_back[curr] = d;
            
            for(auto [nxt, weight] : next[curr])
            {
                if(dist_back[nxt] != INT_MAX/3) continue;
                pq.push({d+weight, nxt});
            }
        }

        // frontpropagation
        vector<int> dist_front(n, INT_MAX/3);
        pq.push({0, source});
        while(!pq.empty())
        {
            auto [d, curr] = pq.top();
            pq.pop();
            if(dist_front[curr] != INT_MAX/3) continue;
            dist_front[curr] = d;

            if(curr == destination && d != target) return {};

            for(auto [nxt, weight] : next[curr])
            {
                if(dist_front[nxt] != INT_MAX/3) continue;
                if(todo[curr][nxt] == 1 && dist_front[curr] + weight + dist_back[nxt] < target)
                {
                    weight = target - dist_front[curr] - dist_back[nxt];
                    next[nxt][curr] = weight;
                    next[curr][nxt] = weight;
                }

                pq.push({d+weight, nxt});
            }
        }

        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            e[2] = next[a][b];
        }

        return edges;
    }
};