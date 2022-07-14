/*
 * @Author: sanjusss
 * @Date: 2022-07-14 08:29:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-14 11:21:39
 * @FilePath: \0\700\740\745_20220714.cpp
 */
#include "leetcode.h"

// struct SuffNode {
//     SuffNode* children[26];
//     int index;
// };

// struct PreNode {
//     PreNode* children[26];
//     SuffNode* suff;
// };

// static constexpr size_t suffmax = 1e6;
// static constexpr size_t premax = 1e5;
// static SuffNode suffnodes[suffmax];
// static PreNode prenodes[premax];

// class WordFilter {
// public:
//     WordFilter(vector<string>& words) {
//         memset(suffnodes, 0, sizeof(suffnodes));
//         memset(prenodes, 0, sizeof(prenodes));
//         int suffi = 0;
//         int prei = 0;
//         int n = words.size();
//         for (int i = 0; i < n; ++i) {
//             auto& s = words[i];
//             auto prefix = m_root;
//             for (char cj : s) {
//                 int j = cj - 'a';
//                 if (prefix->children[j] == nullptr) {
//                     prefix->children[j] = &(prenodes[prei++]);
//                 }

//                 prefix = prefix->children[j];
//                 if (prefix->suff == nullptr) {
//                     prefix->suff = &(suffnodes[suffi++]);
//                     prefix->suff->index = -1;
//                 }

//                 vector<SuffNode*> allSuffix;
//                 for (char ck : s) {
//                     int k = ck - 'a';
//                     allSuffix.push_back(prefix->suff);
//                     for (auto& suffix : allSuffix) {
//                         if (suffix->children[k] == nullptr) {
//                             suffix->children[k] = &(suffnodes[suffi++]);
//                             suffix->children[k]->index = -1;
//                         }

//                         suffix = suffix->children[k];
//                     }
//                 }

//                 for (auto& suffix : allSuffix) {
//                     suffix->index = max(suffix->index, i);
//                 }
//             }
//         }
//     }

//     int f(string pref, string suff) {
//         PreNode* prefix = m_root;
//         for (char ci : pref) {
//             int i = ci - 'a';
//             if (prefix->children[i] == nullptr) {
//                 return -1;
//             }

//             prefix = prefix->children[i];
//         }

//         SuffNode* suffix = prefix->suff;
//         for (char ci : suff) {
//             int i = ci - 'a';
//             if (suffix->children[i] == nullptr) {
//                 return -1;
//             }

//             suffix = suffix->children[i];
//         }

//         return suffix->index;
//     }

// private:
//     PreNode* m_root = new PreNode();
// };

struct Trie {
    Trie* children[26];
    Trie* suff;
    int value;
};

static constexpr size_t nodeCount = 1e6;
static Trie allTries[nodeCount];

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        memset(allTries, 0, sizeof(allTries));
        int trieI = 0;
        m_root = &(allTries[trieI++]);
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            auto& s = words[i];
            auto prefix = m_root;
            for (char cj : s) {
                int j = cj - 'a';
                if (prefix->children[j] == nullptr) {
                    prefix->children[j] = &(allTries[trieI++]);
                }

                prefix = prefix->children[j];

                if (prefix->suff == nullptr) {
                    prefix->suff = &(allTries[trieI++]);
                }
                
                auto suffix = prefix->suff;
                for (auto ri = s.rbegin(); ri != s.rend(); ++ri) {
                    int k = *ri - 'a';
                    if (suffix->children[k] == nullptr) {
                        suffix->children[k] = &(allTries[trieI++]);
                    }

                    suffix = suffix->children[k];
                    suffix->value = i + 1;
                }
            }
        }
    }

    int f(string pref, string suff) {
        Trie* prefix = m_root;
        for (char ci : pref) {
            int i = ci - 'a';
            if (prefix->children[i] == nullptr) {
                return -1;
            }

            prefix = prefix->children[i];
        }

        Trie* suffix = prefix->suff;
        for (auto suffi = suff.rbegin(); suffi != suff.rend(); ++suffi) {
            int i = *suffi - 'a';
            if (suffix->children[i] == nullptr) {
                return -1;
            }

            suffix = suffix->children[i];
        }

        return suffix->value - 1;
    }

private:
    Trie* m_root;
};