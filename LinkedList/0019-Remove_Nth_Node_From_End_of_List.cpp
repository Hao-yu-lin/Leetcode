/*
題目：
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

解說：
計算出長度後，找到倒數第 n 位置在哪，將前一個 node->next 指向 node->next->next

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = head;
        int len = calLen(curr);
        // cout << len;

        curr = dummy;
        for(int i = 0; i < len-n; i++)
        {
            curr = curr->next;
        }
        if(curr->next == nullptr) return dummy->next;

        curr->next = curr->next->next;

        return dummy->next;
    }

    int calLen(ListNode* head){
        int n = 0;
        while(head != nullptr){
            n++;
            head = head->next;
        }

        return n;
    }
};