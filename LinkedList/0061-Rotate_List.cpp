/*
題目：
https://leetcode.com/problems/rotate-list/

解說：
找到要拆分的點後，將 head 連接到要切得點
而 tmp->next = null

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        ListNode* tmp = head;
        int len = 1;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
            len++;
        }

        tmp->next = head;
        k = k%len;
        int end = len-k;    
        while(end--)
        {
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = nullptr;
        return head;
    }
};