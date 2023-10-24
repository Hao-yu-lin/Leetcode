#ifndef CODE_FUNCTION_H_
#define CODE_FUNCTION_H_

#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <deque>
#include <string>
#include <set>
#include <algorithm>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif