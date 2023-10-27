/*
題目：
https://leetcode.com/problems/reverse-linked-list-ii/

解說：


有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1, head);

        // reach node at position "left"
        ListNode* leftPrev = dummy;
        ListNode* curr = head;
        for(int i = 0; i < left-1; i++)
        {
            leftPrev = curr;
            curr = curr->next;
        }

        // now curr = "left", leftPrev = "node before left"
        // reverse from left to right
        ListNode* prev = nullptr;
        for(int i = 0; i < (right-left+1); i++)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // Update pointers
        leftPrev->next->next = curr;    // curr is node after "right"
        leftPrev->next= prev;   // prev is right

        return dummy->next;
    }
};