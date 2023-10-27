/*
題目：
https://leetcode.com/problems/reverse-nodes-in-k-group/

解說：
使用類似於 92 題的觀念，只是要多注意起始值。

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* leftPrev = dummy;
        ListNode* right = dummy;

        while(right != nullptr)
        {
            // 用來判斷是否有 k 個 Node 給予翻轉
            for(int i = 0; i < k; i++)
            {
                right = right->next;
                if(right == nullptr) return dummy->next;
                
            }

            // 紀錄下一個 leftPrev
            ListNode* curr_tmp = leftPrev->next;

            // 開始進行翻轉
            ListNode* prev = nullptr;
            ListNode* curr = leftPrev->next;
            
            for(int i = 0; i < k; i++)
            {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            leftPrev->next->next = curr;
            leftPrev->next = right;

            leftPrev = curr_tmp;
            right = curr_tmp;
        }

        return dummy->next;    
    }
};