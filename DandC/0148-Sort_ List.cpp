/*
題目：
https://leetcode.com/problems/sort-list/

解說：
按照 merge sort 的演算法寫出來

有使用到的觀念：
Merge Sort
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tmp = nullptr;

        while(fast && fast->next)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        tmp->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr= dummy;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val > l2->val)
            {
                curr->next = l2;
                l2 = l2->next;
            }else
            {
                curr->next = l1;
                l1 = l1->next;
            }
             curr = curr->next;
        }

        if(l1 == nullptr && l2 != nullptr)
        {
            curr->next = l2;
            l2 = l2->next;
        }
        if(l1 != nullptr && l2 == nullptr)
        {
            curr->next = l1;
            l2 = l1->next;
        }

        return dummy->next;
    }
};