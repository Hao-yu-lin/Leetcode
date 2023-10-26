/*
題目：
https://leetcode.com/problems/minimum-genetic-mutation/

解說：
使用 hash table 紀錄有效的基因，以及紀錄拜訪過的基因。
使用 startGene 進行 BFS，探訪 bank 中的可能性

有使用到的觀念：
BFS, Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> valid(bank.begin(), bank.end());
        unordered_set<string> visited;

        visited.insert(startGene);
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty())
        {
            auto &temp = q.front();
            q.pop();

            string curr = temp.first;
            int dist = temp.second;

            if(curr == endGene)return dist;
            for(auto mu : find_mu(curr, valid))
            {
                if(visited.count(mu) == 0)
                {
                    q.push({mu, dist+1});
                    visited.insert(mu);
                }
            }
        } 

        return -1;   
    }

    vector<string> find_mu(string curr, unordered_set<string> valid)
    {
        vector<string> mu;
        char dist[4] = {'A', 'C', 'G', 'T'};
        for(int i = 0; i < curr.length(); i++)
        {
            for(int j = 0; j < 4; j++){
                string tmp = curr;
                tmp[i] = dist[j];
                if(valid.count(tmp) != 0){
                    mu.push_back(tmp);
                }
            }
        }

        return mu;
    }
};