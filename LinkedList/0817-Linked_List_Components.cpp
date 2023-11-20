/*
題目：
https://leetcode.com/problems/linked-list-components/

解說：
解法1 自己的解法，使用一個 unordered_set 作為 hash table，
從頭開始查找，如果有出現在 unordered_set 中，compont ++
並且利用一個 while 開始往下尋找，直到 unordered_set 內沒有，則剛剛尋找的都是屬於同一個 compont

有使用到的觀念：

*/

#include "../code_function.h"


class Solution1 {
public:
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());

        int compont = 0;
        while(head != nullptr)
        {
            int val1 = head->val;
            if(s.count(val1))
            {
                compont++;
                while(head != nullptr)
                {
                    val1 = head->val;
                    if(s.count(val1))
                    {
                        s.erase(val1);
                        head = head->next;
                    }else break;
                }
            }
            if(head == nullptr) break;
            head = head->next;
            
        }
        compont += s.size();
        return compont;
    }
};

class Solution2 {
public:
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        const int n = nums.size();
        unordered_set<int> us(nums.begin(), nums.end());
        int cnt = 0;
        bool check = false;

        while(head != nullptr)
        {
            if(us.count(head->val) == 1 && check == false)
            {
                cnt ++;
                check = true;
            }else if(us.count(head->val) == 0) check = false;

            head = head->next;
        }

        return cnt;
    }
};