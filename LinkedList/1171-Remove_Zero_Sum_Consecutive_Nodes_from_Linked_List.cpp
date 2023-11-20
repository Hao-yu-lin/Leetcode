/*
題目：
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

解說：
使用 prefix sum 方式，並使用一個 unordered_set 紀錄 prefix sum 值
若已經出現過，則代表前一次 prexfix sum 出現到這次，這區間加總和為 0，因此要進行 remove
將該區間中每一個 prefix sum 值給刪除

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dummy = new ListNode(-1, head);

        unordered_map<int, ListNode*> ump; // prefixSum, node

        int pSum = 0; // prefixSum
        ump[0] = dummy;

        while(head)
        {
            pSum += head->val;
            if(ump.count(pSum))
            {
                ListNode* tmp_node = ump[pSum]->next;
                int tmp_sum = pSum;
                while(tmp_node != head)
                {
                    tmp_sum += tmp_node->val;
                    ump.erase(tmp_sum);
                    tmp_node = tmp_node->next;
                }
                ump[pSum]->next = head->next;
                
            }else{
                ump[pSum] = head;
            }

            head = head->next;
        }

        return dummy->next;    
    }
};