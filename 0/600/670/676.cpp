/*
 * @Author: sanjusss
 * @Date: 2022-07-11 07:19:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-11 07:55:07
 * @FilePath: \0\600\670\676.cpp
 */
#include "leetcode.h"

class MagicDictionary {
    struct Trie {
        Trie* children[26]{};
        bool end = false;
    };

public:
    MagicDictionary() {
    }

    void buildDict(vector<string> dictionary) {
        for (auto& s : dictionary) {
            Trie* node = m_root;
            for (char c : s) {
                int i = c - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Trie();
                }

                node = node->children[i];
            }

            node->end = true;
        }
    }

    bool search(string searchWord) {
        int n = searchWord.size();
        function<bool(Trie*, int, bool)> dfs = [&](Trie* node, int i, bool hasModify) -> bool {
            if (i == n) {
                return hasModify && node->end;
            }

            int j = searchWord[i] - 'a';
            if (node->children[j] != nullptr && dfs(node->children[j], i + 1, hasModify)) {
                return true;
            }

            if (hasModify) {
                return false;
            }

            for (int k = 0; k < 26; ++k) {
                if (k == j || node->children[k] == nullptr) {
                    continue;
                }

                if (dfs(node->children[k], i + 1, true)) {
                    return true;
                }
            }

            return false;
        };
        return dfs(m_root, 0, false);
    }

private:
    Trie* m_root = new Trie();
};

// class MagicDictionary {
// public:
//     MagicDictionary() {
//     }

//     void buildDict(vector<string> dictionary) {
//         for (auto& s : dictionary) {
//             m_dict[s.size()].push_back(s);
//         }
//     }

//     bool search(string searchWord) {
//         int n = searchWord.size();
//         if (!m_dict.count(n)) {
//             return false;
//         }

//         for (auto& w : m_dict[n]) {
//             int diff = 0;
//             for (int i = 0; i < n && diff < 2; ++i) {
//                 if (w[i] != searchWord[i]) {
//                     ++diff;
//                 }
//             }

//             if (diff == 1) {
//                 return true;
//             } 
//         }

//         return false;
//     }

// private:
//     unordered_map<int, vector<string>> m_dict;
// };