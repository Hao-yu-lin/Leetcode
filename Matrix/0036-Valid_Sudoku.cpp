/*
題目：
https://leetcode.com/problems/valid-sudoku/

解說：
分成檢查 row, column and 3x3 ，分開檢查後回傳 bool

有使用到的觀念：
Matrix
*/

#include "../code_function.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // return checkrow(board);
        return checkrow(board) && checkcol(board) && checkcenter(board);
    }

    bool checkrow(vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i = 0; i < 9; i++)
        {
            fill(count.begin(), count.end(), 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
  
                    count[board[i][j] - '0']++;
                    if(count[board[i][j] - '0'] > 1) return false;
                }
                
            }
        }
        return true;
    }

    bool checkcol(vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i = 0; i < 9; i++)
        {
            fill(count.begin(), count.end(), 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    count[board[j][i] - '0']++;
                    if(count[board[j][i] - '0'] > 1) return false;
                }
                
            }
        }
        return true;
    }

    bool checkcenter(vector<vector<char>>& board)
    {
        vector<int> count(10, 0);
        for(int i = 0; i < 3; i++)
        {
           
            for(int j = 0; j < 3; j++)
            {
                fill(count.begin(), count.end(), 0);
                for(int x = 0; x < 3; x++)
                {
                    
                    for(int y = 0; y < 3; y++)
                    {
                        if(board[3*i+x][3*j+y] != '.')
                        {
                            count[board[3*i+x][3*j+y] - '0']++;
                            if(count[board[3*i+x][3*j+y] - '0'] > 1) return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }
};