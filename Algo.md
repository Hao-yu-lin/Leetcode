# Some Leetcode Note

# Algo
## Knapsack
obj[i], cap
dp[c]：the maximum goal if using c

### 01 Knapsack
    for i in obj:
        for c in capacity:
            dp[i][c] = max(dp[i-1][c], dp[i-1][c-cost[i]]+val[i])

### Unbounded Knapsack
    for c in capacity:
        for i in obj:
            dp[c] = max{dp[c], val[i]+dp[c-cost[i]}]

# STL
## vector
### 2-dim vector
    int row;    // m
    int col;    // n
    1. vector<int> row(n);
        vector<vector<int>> v(m, row);
    2. vector<vector<int>> v(m, vector<int>(n));
    
### sort
    vector<int> v;
    //  increase
    sort(v.begin(), v.edn());
    // decrease
    sort(v.begin(), v.edn(), std::greater<int>());