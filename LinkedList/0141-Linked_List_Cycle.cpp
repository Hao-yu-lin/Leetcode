/*
題目：
https://leetcode.com/problems/linked-list-cycle/

解說：
使用 fast 指標與 slow 指標，fast 指標一次移動兩格而 slow 指標一次只移動一格。
當 fast 與 slow 相遇時，代表有 cycle 的產生。

有使用到的觀念：
Linked List, Two Pointers
*/

#include "../code_function.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        struct ListNode *fast = head->next;
        struct ListNode *slow = head;

        while(fast && fast->next)
        {
            if(fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};