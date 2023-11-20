/*
題目：
https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

解說：
題目要刪除兩邊，從刪除一個邊開始著手，枚舉其中一條邊(a, b)，刪除後會形成兩棵樹 A, B，分別以 a 和 b 作為 root。
此時還需要再砍一條邊，因此該邊只能存在於 A 或 B 中。
假設砍在 A 中，針對 B 只需將 B 中的全部節點 XOR 即可。

接下來探討第二刀的部分，同樣概念，任意砍一邊形成另一顆子樹 C
因此只需要計算 C 子樹的 XOR 剩下的 A-C 子樹透過 A^C 即可求得
最終形成 B, C, A^C 三個部分的 XOR 值
要得到這個值，透過 DFS 方式求得


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int n;
    vector<int> nums;
    unordered_set<int> next[1005];
    int visited[1005];
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        this->n = nums.size();
        this->nums = nums;

        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            next[a].insert(b);
            next[b].insert(a);
        }

        int ans = INT_MAX;
        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            next[a].erase(b);
            next[b].erase(a);

            int ret1 = solve(a, b); //{分割, 保留}
            int ret2 = solve(b, a);

            ans = min(ans, min(ret1, ret2));

            next[a].insert(b);
            next[b].insert(a);
        }

        return ans;
    }

    int solve(int a, int b)
    {
        fill(visited, visited+n, 0);
        visited[a] = 1;
        int A = getAll(a);

        fill(visited, visited+n, 0);
        visited[b] = 1;
        int B = getAll(b);

        int ret = INT_MAX;
        fill(visited, visited+n, 0);
        visited[a] = 1;
        dfs(a, ret, A, B);
        return ret;
    }

    int getAll(int node)
    {
        int total = 0;
        for(int nxt : next[node])
        {
            if(visited[nxt] == 1) continue;
            visited[nxt] = 1;
            total ^= getAll(nxt);
        }

        total ^= nums[node];
        return total;
    }

    int dfs(int node, int& ret, int A, int B)
    {
        int total = 0;
        for(int nxt: next[node])
        {
            if(visited[nxt] == 1)continue;
            visited[nxt] = 1;

            int C = dfs(nxt, ret, A, B);
            int other = A^C;
            int mx = max(other, max(C, B));
            int mn = min(other, min(C, B));
            ret = min(ret, mx-mn);

            total ^= C;
        }
        total ^= nums[node];
        return total;
    }
};