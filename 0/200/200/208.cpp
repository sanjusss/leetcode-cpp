#include "leetcode.h"

class Trie {
    struct Node {
        ~Node() {
            for (auto& i : children) {
                delete i;
                i = nullptr;
            }
        }

        array<Node*, 26> children = { 0 };
        bool end = false;
    };

public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = &m_root;
        for (char i : word) {
            if (cur->children[i - 'a'] == nullptr) {
                cur->children[i - 'a'] = new Node();
            }

            cur = cur->children[i - 'a'];
        }

        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = &m_root;
        for (char i : word) {
            if (cur->children[i - 'a'] == nullptr) {
                return false;
            }
            else {
                cur = cur->children[i - 'a'];
            }
        }

        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = &m_root;
        for (char i : prefix) {
            if (cur->children[i - 'a'] == nullptr) {
                return false;
            }
            else {
                cur = cur->children[i - 'a'];
            }
        }

        return true;
    }

private:
    Node m_root;
};