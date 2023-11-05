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

sort by start points：the minimum number of intervals to cover<br>
sort by end points：the maximum number of non-overlapping intervals<br>

    static bool cmp(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    sort(points.begin(), points.end(), cmp);

## bound
### lower_bound
找出 vector 中大於或等於 val 的最小值的位置

### upper_bound
找出 vector 中大於 val 的最小值位置

## priority_queue
    priority_queue<int> pq; 預設由大排到小
    prioirty_queue<int, vector<int>, greater<int>> pq; 由小排到大
### 使用自定義
    struct cmp{
        bool operator()(const int& a, const int& b){
            return a < b;
        }
    }
    prioirty_queue<int, vector<int>, cmp<int>>

因為優先判定為 !cmp，因此如果要由大排到小，需要反向定義