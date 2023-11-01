/*
題目：
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

解說：
使用 Queue 紀錄該層有哪些 Node，然後將 Next 連接起來。

有使用到的觀念：
Linked List, BFS, Binary Tree
*/

#include "../code_function.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<Node*> next;
            while(size--)
            {
                Node *tmp = q.front();
                next.push_back(tmp);
                q.pop();

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);    
            }

            for(int i = 0; i < next.size()-1; i++)
            {
                next[i]->next = next[i+1];
            }
            next[next.size()-1]->next = nullptr;
        }

        return root;
    }
};