/*
題目：
https://leetcode.com/problems/word-ladder/

解說：
與 433. Minimum Genetic Mutation 同樣概念

有使用到的觀念：
BFS
*/

#include "../code_function.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.length();
        int step = 0;
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {                
                string w = q.front();                
                q.pop();
                for (int i = 0; i < l; i++) {                
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        // Found the solution
                        if (w == endWord) return step + 1;
                        // Not in dict, skip it
                        if (!dict.count(w)) continue;
                        // Remove new word from dict
                        dict.erase(w);
                        // Add new word into queue
                        q.push(w);                    
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
};