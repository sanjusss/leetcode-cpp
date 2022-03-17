/*
 * @Author: sanjusss
 * @Date: 2022-03-17 08:44:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-17 08:55:37
 * @FilePath: \0\700\720\720.cpp
 */
#include "leetcode.h"

struct Trie {
    bool end = false;
    Trie* children[26] {  };
    ~Trie() {
        for (auto i : children) {
            delete i;
        }
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie root;
        for (auto& s : words) {
            Trie* node = &root;
            for (char c : s) {
                int i = c - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Trie();
                }

                node = node->children[i];
            }

            node->end = true;
        }

        stack<pair<Trie*, int>> s;
        string ans;
        string cur;
        s.emplace(&root, 0);
        while (!s.empty()) {
            auto& [node, i] = s.top();
            if (i == 26) {
                s.pop();
                cur.pop_back();
                continue;
            }

            if (node->children[i] == nullptr || node->children[i]->end == false) {
                ++i;
                continue;
            }

            cur.push_back(i + 'a');
            if (cur.size() > ans.size()) {
                ans = cur;
            }

            s.emplace(node->children[i], 0);
            ++i;
        }

        return ans;
    }
};