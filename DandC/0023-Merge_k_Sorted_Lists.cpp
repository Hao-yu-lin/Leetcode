/*
題目：
https://leetcode.com/problems/merge-k-sorted-lists/

解說：
解法1：使用 merge sort 的 merge，按照順序一個一個比較合併

解法2：使用 minHeap，將每個 lists 的頭 Node 放入 minHeap 後
minHeap.top 為目前的最小 Node，放入新建的 Node 後
再從該 list 挑選頭一個 Node 放入 minHeap

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {     
        const int n = lists.size();
        if(n == 0) return {};
        ListNode* head = lists[0];
        for(int i = 1; i < n; i++)
        {
            head = merge(head, lists[i]);
        }

        return head;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

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

        if(l1 != nullptr) curr->next = l1;
        if(l2 != nullptr) curr->next = l2;

        return dummy->next;
    }
};

class Solution2 {
    struct compareNode{
        bool operator()(const pair<ListNode*, int>& a, const pair<ListNode*, int>& b){
            return a.first->val > b.first->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, compareNode> minHeap;

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i]) minHeap.push({lists[i], i});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int listIndex = top.second;
            ListNode* node = top.first;

            curr->next = node;
            curr = curr->next;

            if(node->next) minHeap.push({node->next, listIndex});
        }

        return dummy->next;
    }
};