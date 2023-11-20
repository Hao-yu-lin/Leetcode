/*
題目：
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

解說：
使用 ascending 排序，因此取 List 中點後，左邊放置在左子樹，右邊放置在右子樹
即可得到一個 Balanced Binary Tree

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == nullptr) return nullptr;

        if(head->next == nullptr)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }

        if(head->next->next == nullptr)
        {
            TreeNode* root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
            return root;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tmp;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        tmp->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};