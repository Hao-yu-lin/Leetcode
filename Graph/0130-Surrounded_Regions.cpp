/*
題目：
https://leetcode.com/problems/surrounded-regions/

解說：


有使用到的觀念：
DFS
*/

#include "../code_function.h"

class Solution {
private:
    int m;
    int n;

    map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        for(int j = 0; j < n; j++){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = v[board[i][j]];
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = 'G';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};