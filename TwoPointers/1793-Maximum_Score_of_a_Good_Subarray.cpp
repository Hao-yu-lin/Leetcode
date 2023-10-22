/*
題目：
https://leetcode.com/problems/maximum-score-of-a-good-subarray/

解說：
因為 nums[i] 的數值皆是正數，因此在固定 minVal 的情形下，區間越大所得到的值也會越大。
從 k 開始往左往右擴展區間，直到碰到比 nums[k] 還小的數值，此時會得到一個初始的答案 numx[k] * (r-l+1)

若想要繼續往外擴展，選定左右值中較大的，作為新的 minVal，開始重新往左往右擴展區間，計算新的區間答案，直到左右指針越界。

有使用到的觀念：
Array、Two Pointers
*/
#include <vector>
class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        const int n = nums.size();
        int l = k, r = k;
        int minVal = nums[k];
        
        int ans = 0;

        while(l >= 0 || r < n)
        {
            while(l >= 0 && nums[l] >= minVal)l--;
            while(r < n && nums[r] >= minVal) r++;
            ans = std::max(ans, minVal * (r-l-1));
            minVal = std::max( l>=0 ? nums[l]:0, r<n ? nums[r]:0);
        }
        return ans;
    }
};