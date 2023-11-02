/*
題目：
https://leetcode.com/problems/word-search/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    bool state = false;
    int m;
    int n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(board, word, 0, i, j);
        return state;
    }

    void dfs(vector<vector<char>>& board, string word, int curr, int i, int j)
    {
        if(state == true) return;
        if(curr == word.length()){
            state = true;
            return;
        }
        if(i < 0 || i >= m || j < 0 || j >= n ) return;

        if(word[curr] == board[i][j])
        {
            board[i][j] = '.';
            dfs(board, word, curr+1, i+1, j);
            dfs(board, word, curr+1, i-1, j);
            dfs(board, word, curr+1, i, j+1);
            dfs(board, word, curr+1, i, j-1);
            board[i][j] = word[curr];
        }
    }
};