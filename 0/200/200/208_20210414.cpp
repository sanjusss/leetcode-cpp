#include "leetcode.h"

class Trie {
    struct Node {
        array<Node*, 26> children = { 0 };
        bool end = false;

        ~Node() {
            for (auto i : children) {
                delete i;
            }
        }
    };

public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = & m_root;
        for (char i : word) {
            if (node->children[i - 'a'] == nullptr) {
                node->children[i - 'a'] = new Node();
            }

            node = node->children[i - 'a'];
        }

        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = & m_root;
        for (char i : word) {
            if (node->children[i - 'a'] == nullptr) {
                return false;
            }

            node = node->children[i - 'a'];
        }

        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = & m_root;
        for (char i : prefix) {
            if (node->children[i - 'a'] == nullptr) {
                return false;
            }

            node = node->children[i - 'a'];
        }

        return true;
    }

private:
    Node m_root;
};