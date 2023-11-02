/*
題目：
https://leetcode.com/problems/n-queens-ii/

解說：
這是 DFS 題目，繪製出一個棋盤，從上至下一行一行擺放旗子
擺放的過程中需檢查 該行 、 該列 、 左斜上方 、 右斜上方 是否有棋子

有使用到的觀念：
DFS
*/

#include "../code_function.h"

class Solution {
    int n;
    int ans = 0;
    vector<string> board;
public:
    int totalNQueens(int n) 
    {
        this->n = n;
        string tmp;
        for(int i = 0; i < n; i++)
            tmp.push_back('.');
        for(int i = 0; i < n; i++)
            board.push_back(tmp);

        dfs(0);
        return ans;
    }

    void dfs(int i)
    {
        if(i == n)
        {
            ans++;
            return;
        }

        for(int j = 0; j < n; j++)
        {
            if(isValid(i, j))
            {
                board[i][j] = 'Q';
                dfs(i+1);
                board[i][j] = '.';
            }
        }
    }

    bool isValid(int row, int col)
    {
        for(int i = 0; i < row; i++)
        {
            if(board[i][col] == 'Q') return false;
        }

        for(int j = 0; j < col; j++)
        {
            if(board[row][j] == 'Q') return false;
        }

        //  左斜上方
        int k = 1;
        while(row - k >= 0 && col - k >= 0)
        {
            if(board[row-k][col-k] == 'Q') return false;
            k++;
        }
        k = 1;
        while(row - k >= 0 && col + k < n)
        {
            if(board[row-k][col+k] == 'Q') return false;
            k++;
        }

        return true;
    }
};