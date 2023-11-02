/*
題目：
https://leetcode.com/problems/word-search-ii/

解說：


有使用到的觀念：
TrieNode
*/

#include "../code_function.h"

class TrieNode{
public:
    vector<TrieNode*> nodes;
    const string* word;
    TrieNode(): nodes(26), word(nullptr){}
    ~TrieNode(){
        for(auto node : nodes) delete node;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        
        for(const string& word : words){
            TrieNode* curr = &root;
            for(char c : word){
                auto& next = curr->nodes[c-'a'];
                if(!next) next = new TrieNode();
                curr = next;
            }
            curr->word = &word;
        }

        const int m = board.size();
        const int n = board[0].size();
        vector<string> ans;
        
        function<void(int, int, TrieNode*)> walk = [&](int x, int y, TrieNode * node){
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '.') return;
            const char cur = board[x][y];
            TrieNode* next_node = node->nodes[cur - 'a'];

            if(!next_node) return;
            if(next_node->word){
                ans.push_back(*next_node->word);
                next_node->word = nullptr;
            }
            board[x][y] = '.';
            walk(x+1, y, next_node);
            walk(x-1, y, next_node);
            walk(x, y+1, next_node);
            walk(x, y-1, next_node);
            board[x][y] = cur;  
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                walk(i, j, &root);
            }
        }
        return ans;
    }
};