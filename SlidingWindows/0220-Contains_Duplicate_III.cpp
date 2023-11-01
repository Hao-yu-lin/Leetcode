/*
題目：
https://leetcode.com/problems/contains-duplicate-iii

解說：
solution1:
使用一個 vector 紀錄 <nums[i], i> 數組與位置之間的關係，之後進行 sorting
此時 vector 會先按照 nums[i] 進行排序，如果有同樣的 nums[i] 則透過位置排序

接下來按照順序檢查 vector 每一個數組是否符合

solution2:
使用 multiset 來保留重複元素，並且資料會由小到大排序
如果 j > indexDiff 此時代表距離已經超過 indexDiff，此時必須刪除最前排的 nums[j-indexDiff-1] 
來使得整體數值距離仍然在 indexDiff內
因為 multiset 已經進行排序，因此找 nums[j] - valueDiff 的 lower_bound 是否存在於 multiset 中
lower_bound -> 在 multiset 中大於或等於 nums[j] - valueDiff 的最小位置
因此如果 pos == nums.end 代表全部的值都小魚 nums[j]-valueDiff ，代表著目前 multiset 中沒有符合 valueDiff 的情形

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        vector<pair<int, int>> arr(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            arr[i].first = nums[i];
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end());

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(arr[i].first + valueDiff >= arr[j].first){
                    if(abs(arr[i].second - arr[j].second) <= indexDiff) return true;
                }else break;
                    
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<long>ms;

        for(int j = 0; j < nums.size(); j++)
        {
            // 如果 j > indexDiff 代表超過 indexDiff 需要刪除前面的
            if(j>indexDiff) ms.erase(ms.lower_bound(nums[j-indexDiff-1])); 

            // nums[j]- valueDiff <= nums[i] <= nums[j] + valueDiff
            auto pos = ms.lower_bound((long)nums[j]-(long)valueDiff);

            if(pos != ms.end() && *pos-nums[j] <= valueDiff) return true;

            ms.insert(nums[j]);
        }

        return false; 
    }
};