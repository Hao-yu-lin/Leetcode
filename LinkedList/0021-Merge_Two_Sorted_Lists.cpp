/*
題目：
https://leetcode.com/problems/merge-two-sorted-lists/

解說：
建立一個 dummy 用於保存排序後的 Node
兩個 list 由頭至尾一一比較大小，較小的 Node 則將該 Node 拆除放入 dummy 中。
記得將 Node -> next 設定為 nullptr 用以確保與原 list 分離

有使用到的觀念：
Linked List
*/

#include "../code_function.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val >= list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
                curr->next = nullptr;
            }else{
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
                curr->next = nullptr;
            }
        }
        if(list1 == nullptr){
            curr->next = list2;
        }

        if(list2 == nullptr){
            curr->next = list1;
        }

        return dummy->next;
    }
};