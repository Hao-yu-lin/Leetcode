/*
題目：
https://leetcode.com/problems/partition-list/

解說：
使用兩個 ListNode，左邊紀錄 < x 右邊紀錄 >= x
最後再合併

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* left_head = left;
        ListNode* right_head = right;

        while(head != nullptr)
        {
            if(head->val < x){
                left->next = head;
                left = left->next;
            }
            else{ 
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        left->next = right_head->next;
        right->next = nullptr;
        return left_head->next;
    }
};