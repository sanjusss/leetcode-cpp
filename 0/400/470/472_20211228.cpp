/*
 * @Author: sanjusss
 * @Date: 2021-12-28 20:47:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-28 21:14:11
 * @FilePath: \0\400\470\472_20211228.cpp
 */
#include "leetcode.h"

class Solution {
    struct Node {
        bool end = false;
        Node* children[26] = { nullptr };
        ~Node() {
            for (auto node : children) {
                delete node;
            }
        }
    };

    struct Trie {
        void insert(const string& s) {
            Node* node = &root;
            for (char c : s) {
                int i = c - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Node();
                }

                node = node->children[i];
            }

            node->end = true;
        }

        bool find(const string& s) {
            if (s.empty()) {
                return false;
            }

            vector<bool> used(s.size());
            return find(s, 0, &root, used);
        }

        bool find(const string& s, int i, Node* node, vector<bool>& used) {
            if (i == s.size()) {
                return true;
            }

            while (i < s.size()) {
                int j = s[i] - 'a';
                if (node->children[j] == nullptr) {
                    return false;
                }

                node = node->children[j];
                if (node->end && !used[i]) {
                    used[i] = true;
                    if (find(s, i + 1, &root, used)) {
                        return true;
                    }
                }

                ++i;
            }

            return node->end;
        }

        Node root;
    };

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        Trie tree;
        vector<string> ans;
        for (auto& s : words) {
            if (tree.find(s)) {
                ans.push_back(s);
            }

            tree.insert(s);
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findAllConcatenatedWordsInADict)