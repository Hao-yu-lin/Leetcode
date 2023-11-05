/*
題目：
https://leetcode.com/problems/find-median-from-data-stream/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class MedianFinder {
public:
    MedianFinder() {
        max_size = 0;
        min_size = 0;
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num <= max_heap.top()){
            max_heap.push(num);
            max_size ++;
        }else{
            min_heap.push(num);
            min_size ++;
        }

        if(max_size > min_size + 1){
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
            max_size --;
            min_size ++;
        }else if(min_size > max_size){
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
            max_size ++;
            min_size --;
        }
    }
    
    double findMedian() {
        
        if(min_size == max_size){

            double ans = (max_heap.top()/2.0) + (min_heap.top()/2.0);
            return ans;
        }
        return max_heap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int max_size;
    int min_size;
};
