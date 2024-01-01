/*
題目：
https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Graph {
    int n;
    int dp[100][100];
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        // Initially, set all edge lengths to INT_MAX/3.;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                dp[i][j] = INT_MAX/3;
            dp[i][i] = 0;
        }

        // edges[i] = [from, to, weights]
        for(auto& p : edges)
        {   
            dp[p[0]][p[1]] = p[2];
        }

        // floyad algo.
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
    
    void addEdge(vector<int> edge) 
    {
        int from = edge[0], to = edge[1];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][from] + edge[2] + dp[to][j]);
    }
    
    int shortestPath(int node1, int node2) 
    {
        if(dp[node1][node2] == INT_MAX/3) return -1;
        return dp[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */