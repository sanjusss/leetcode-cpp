#include "leetcode.h"

class WordFilter {
    struct Trie {
        array<Trie*, 27> children = { 0 };
        int maxWeight = 0;
    };

public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        int maxNodesCount = 0;
        for (int i = 0; i < n; ++i) {
            int len = words[i].size();
            maxNodesCount += (len + 1) * (len + 1) + (len + 1) * len  / 2;
        }

        m_nodes.resize(maxNodesCount);

        for (int i = 0; i < n; ++i) {
            int len = words[i].size();
            for (int j = 0; j <= len; ++j) {
                insertSuffix(words[i], j, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        Trie* cur = &root;
        for (char i : suffix) {
            if (cur->children[i - 'a'] == nullptr) {
                return -1;
            }
            else {
                cur = cur->children[i - 'a'];
            }
        }

        if (cur->children[26] == nullptr) {
            return -1;
        }
        else {
            cur = cur->children[26];
        }

        for (char i : prefix) {
            if (cur->children[i - 'a'] == nullptr) {
                return -1;
            }
            else {
                cur = cur->children[i - 'a'];
            }
        }

        return cur->maxWeight;
    }

private:
    void insertSuffix(const string& s, int len, int weight) {
        Trie* cur = &root;
        cur->maxWeight = max(cur->maxWeight, weight);
        int n = s.size();
        for (int i = len; i > 0; --i) {
            cur = insert(cur, s[n - i] - 'a', weight);
        }

        cur = insert(cur, 26, weight);
        for (char i : s) {
            cur = insert(cur, i - 'a', weight);
        }
    }

    Trie* insert(Trie* cur, int i, int weight) {
        if (cur->children[i] == nullptr) {
            cur->children[i] = &(m_nodes[m_next++]);
        }

        cur = cur->children[i];
        cur->maxWeight = max(cur->maxWeight, weight);
        return cur;
    }

private:
    Trie root;
    vector<Trie> m_nodes;
    int m_next = 0;
};