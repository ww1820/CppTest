/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Trie
{
public:
    Trie() : children(26,nullptr), isEnd(false) {

    }
    
    void insert(string word) {
        Trie *cur = this;
        for(const char ch : word) {
            if (cur->children[ch - 'a'] == nullptr) { // 没有找到该子节点
                cur->children[ch - 'a'] = new Trie();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie * node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }

private:
    vector<Trie *> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie *cur = this;
        int len = prefix.length();
        for (int i = 0; i < len; ++i) {
            if(cur->children[prefix[i]-'a'] == nullptr)
                return nullptr;
            cur = cur->children[prefix[i]-'a'];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

