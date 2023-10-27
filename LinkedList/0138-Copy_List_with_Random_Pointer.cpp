/*
題目：
https://leetcode.com/problems/copy-list-with-random-pointer/

解說：
clone 的套路就是使用 unordered_map 作為原始的與拷貝的 Node 指引

有使用到的觀念：
Linked List, Hash Table
*/

#include "../code_function.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        unordered_map<Node*, Node*> ump; // {orig, copy};
        Node* curr = head;
        Node* clone = new Node(-1);
        Node* copy = clone;

        while(curr != nullptr)
        {
            Node* tmp = new Node(curr->val);
            ump[curr] = tmp;
            copy->next = tmp;
            copy = copy->next;
            curr = curr->next;
        }

        copy = clone->next;
        curr = head;

        while(curr != nullptr)
        {
            copy->random = ump[curr->random];
            copy = copy->next;
            curr = curr->next;
        }

        return clone->next;
    }
};