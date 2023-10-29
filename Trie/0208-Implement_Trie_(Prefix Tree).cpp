/*
題目：


解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Trie {
public:
    Trie() : root_(new TrieNode()){
        
    }
    
    void insert(string word) {
        TrieNode* p = root_.get();
        for(const char c : word){
            if(!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->is_word = true;
    }
    
    bool search(string word) {
        const TrieNode* p = find(word);
        return p && p->is_word;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode{
        TrieNode():is_word(false), children(26, nullptr){}

        ~TrieNode(){
            for(TrieNode* child : children){
                if(child) delete child;
            }
        }

        bool is_word;
        vector<TrieNode*> children;
    };

    const TrieNode* find(const string& prefix) const{
        const TrieNode* p = root_.get();
        for(const char c : prefix){
            p = p->children[c - 'a'];
            if(p == nullptr) break;
        }
        return p;
    }

    unique_ptr<TrieNode> root_;
};