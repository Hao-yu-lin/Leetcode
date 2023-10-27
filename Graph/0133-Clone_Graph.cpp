/*
題目：
https://leetcode.com/problems/clone-graph/

解說：
使用 hash table 紀錄，已原 Node 與拷貝的 Node。
透過 BFS 方式針對每一個 Node 逐層搜索。

有使用到的觀念：
BFS, Hash Table
*/

#include "../code_function.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> ump;

        Node* clone = new Node(node->val);
        ump[node] = clone;

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            Node* tmp = q.front();
            q.pop();

            for( Node* neigh : tmp->neighbors)
            {
                if(!ump.count(neigh)){
                    Node* clone_n = new Node(neigh->val);
                    ump[neigh] = clone_n;
                    q.push(neigh);
                }

                ump[tmp]->neighbors.push_back(ump[neigh]);
            }
        }   
        return clone; 
    }
};