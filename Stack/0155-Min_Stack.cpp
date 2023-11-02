/*
題目：
https://leetcode.com/problems/min-stack/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class MinStack {
    stack<int> minstack;
    stack<int> elestack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty() || minstack.top() > val) minstack.push(val);
        else minstack.push(minstack.top());

        elestack.push(val);
    }
    
    void pop() {
        minstack.pop();
        elestack.pop();
    }
    
    int top() {
        return elestack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
