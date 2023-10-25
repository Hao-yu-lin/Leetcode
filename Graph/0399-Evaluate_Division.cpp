/*
題目：
https://leetcode.com/problems/evaluate-division/

解說：
這題的觀念在於 使用除法的連續性。
比方說 a/b = 2.0, b/c = 3.0 -> a/c = 6.0

一開始先將 a/b 與 b/a 透過 hash table 給予配對，依序計算 queries 內的值，使用除法連續性，得到結果

有使用到的觀念：
Graph
*/

#include "../code_function.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;

        for(int i = 0; i < equations.size(); i++){
            string& A = equations[i][0];
            string& B = equations[i][1];

            double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0/k;
        }

        vector<double> ans;
        for(const auto& pair : queries){
            const string& X = pair[0];
            const string& Y = pair[1];

            if(!g.count(X) || !g.count(Y)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(divid(X, Y, g, visited));
        }

        return ans;
    }

    double divid(const string& A, const string& B, unordered_map<string, unordered_map<string, double>>& g,
            unordered_set<string>& visited){
            if(A == B) return 1.0;
            visited.insert(A);
            for(const auto& gpair : g[A]){
                const string& C = gpair.first;
                if(visited.count(C)) continue;
                double d = divid(C, B, g, visited);

                if(d > 0) return d * g[A][C];
            }
            return -1.0;
        }
};