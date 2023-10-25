/*
題目：
https://leetcode.com/problems/add-two-numbers/

解說：
建立一個新的 node ，用於儲存 sum 所建立的每一個位數的值

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int sum = 0;

        while(l1 != nullptr || l2 != nullptr || sum != 0)
        {
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            sum = sum + l1Val + l2Val;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            tail->next = new ListNode(sum%10);
            sum /= 10;
            tail = tail->next;
        }
        return dummy->next;
    }
};