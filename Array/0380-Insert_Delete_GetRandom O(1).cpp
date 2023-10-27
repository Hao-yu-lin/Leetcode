/*
題目：
https://leetcode.com/problems/insert-delete-getrandom-o1/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class RandomizedSet {
private:
    unordered_map<int, int>m;
    vector<int> array;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end())  return false;
        else{
            array.push_back(val);
            m[val] = array.size() - 1;

            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        else{
            int last = array.back();
            array[m[val]] = array.back();

            array.pop_back();
            m[last] = m[val];
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return array[rand() % array.size()];
    }
};