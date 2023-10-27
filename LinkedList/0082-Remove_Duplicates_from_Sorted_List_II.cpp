/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

解說：
判斷該點值與下一個點值是否相等

有使用到的觀念：
Linked List
*/

#include "../code_function.h"


// 一開始想到的方法 較耗費空間跟時間，紀錄每一個點出現次數，再進行刪除
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        unordered_map<int, int> count;

        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr != nullptr)
        {
            count[curr->val] ++;
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr)
        {
            if(count[curr->val] > 1){
                curr = curr->next;
            }else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }

        prev->next = nullptr;
        return dummy->next;


    }
};

// 正常解法

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr)
        {
            if(curr->val == curr->next->val)
            {
                int val = curr->val;
                curr = curr->next;
                while(curr != nullptr && val == curr->val)
                    curr = curr->next;
                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};