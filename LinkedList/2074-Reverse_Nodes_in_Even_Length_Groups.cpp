/*
題目：
https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

解說：
使用兩個指針 start, end
start 代表著前一個區間的尾巴，start->next 區間的頭
end 代表著區間的尾巴
當該 group 長度為偶數時，就執行 reverse
在 reverse 前因為翻轉後，start 與 end 會指向不同地方，因此須先儲存下一個 group 的位置

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        int curr_group = 1;
        int count = 0;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* start = dummy;
        ListNode* end = dummy;
        

        while(end->next != nullptr)
        {
            while(end->next != nullptr && count != curr_group)
            {
                end = end->next;
                count++;
            }
            ListNode* tmp = end->next;
            if(count % 2 == 0)
            {
                end = reverseGroup(start, end);
                end->next = tmp;
            }
            start = end;
            curr_group++;
            count = 0;
        }
        return head;
    }

    ListNode* reverseGroup(ListNode* start, ListNode* end)
    {
        ListNode* curr = start->next;
        ListNode* prev = nullptr;

        while(curr != end)
        {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = prev;
            prev = tmp;
        }
        ListNode* last = start->next;
        curr->next = prev;
        start->next = curr;

        return last;
    }
};