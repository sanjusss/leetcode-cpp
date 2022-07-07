/*
 * @Author: sanjusss
 * @Date: 2022-07-07 08:42:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-07 08:53:27
 * @FilePath: \0\600\640\648.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        struct Trie {
            Trie* children[26] = {};
            bool end = false;
        };

        Trie* root = new Trie();
        for (string& s : dictionary) {
            Trie* node = root;
            for (char c : s) {
                int i = c - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Trie();
                }

                node = node->children[i];
            }

            node->end = true;
        }

        string ans;
        int n = sentence.size();
        bool skip = false;
        Trie* cur = root;
        for (int i = 0; i < n; ++i) {
            if (sentence[i] == ' ') {
                skip = false;
                ans += ' ';
                cur = root;
            }
            else if (skip == false) {
                ans += sentence[i];
                if (cur != nullptr) {
                    cur = cur->children[sentence[i] - 'a'];
                    if (cur != nullptr && cur->end) {
                        skip = true;
                    }
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::replaceWords)