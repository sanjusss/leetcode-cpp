/*
 * @Author: sanjusss
 * @Date: 2021-07-26 10:47:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-26 12:50:46
 * @FilePath: \C\C200\C250\C251\4.cpp
 */
#include "leetcode.h"

class Solution {
    struct Node {
        string key;
        unordered_map<string, Node*> children;
    };

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& p : paths) {
            insert(p);
        }

        dfsCompleteKey(root);
        vector<string> cur;
        dfsGenAns(cur, root);
        return move(ans);
    }

private:
    void insert(const vector<string>& path) {
        Node* node = root;
        for (auto& dir : path) {
            if (node->children[dir] == nullptr) {
                node->children[dir] = new Node();
            }

            node = node->children[dir];
        }
    }

    void dfsCompleteKey(Node* node) {
        for (auto& [dir, child] : node->children) {
            dfsCompleteKey(child);
            if (!child->key.empty()) {
                ++freq[child->key];
            }

            node->key += dir + "("s + child->key + ")"s;
        }
    }

    void dfsGenAns(vector<string>& cur, Node* node) {
        for (auto& [dir, child] : node->children) {
            if (freq[child->key] > 1) {
                continue;
            }

            cur.push_back(dir);
            ans.push_back(cur);
            dfsGenAns(cur, child);
            cur.pop_back();
        }
    }

private:
    Node* root = new Node();
    unordered_map<string, int> freq;
    vector<vector<string>> ans;
};

// class Solution {
//     struct Node {
//         size_t code;
//         unordered_map<int, Node*> children;
//     };

//     static void hashCombine(size_t& seed, size_t val) {
//         seed ^= val + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//     }

//     struct NodeHash {
//         size_t operator()(Node* node) const {
//             size_t code = 1e9 + 7;
//             for (auto& [i, child] : node->children) {
//                 hashCombine(code, i);
//                 hashCombine(code, child->code);
//             }

//             return code;
//         }
//     };

//     struct NodeEqual {
//         bool operator()(Node* a, Node* b) const {
//             if (a->children.size() != b->children.size()) {
//                 return false;
//             }

//             for (auto& [ai, ac] : a->children) {
//                 auto p = b->children.find(ai);
//                 if (p == b->children.end() || !this->operator()(ac, p->second)) {
//                     return false;
//                 }
//             }

//             return true;
//         }
//     };

// public:
//     vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
//         completeTrie(paths);
//         completeFreq(root);
//         vector<string> cur;
//         dfsGenAns(cur, root);
//         return move(ans);
//     }

// private:
//     void completeTrie(const vector<vector<string>>& paths) {
//         int index = 0;
//         for (auto& path : paths) {
//             Node* node = root;
//             for (auto& dir : path) {
//                 auto p = s2i.find(dir);
//                 int i;
//                 if (p == s2i.end()) {
//                     i = index++;
//                     s2i[dir] = i;
//                     i2s[i] = dir;
//                 }
//                 else {
//                     i = p->second;
//                 }

//                 if (node->children[i] == nullptr) {
//                     node->children[i] = new Node();
//                 }
                
//                 node = node->children[i];
//             }
//         }
//     }

//     void completeFreq(Node* node) {
//         for (auto& [i, child] : node->children) {
//             completeFreq(child);
//             child->code = hashCalc(child);
//             if (!child->children.empty()) {
//                 ++freq[child];
//             }
//         }
//     }

//     void dfsGenAns(vector<string>& cur, Node* node) {
//         for (auto& [i, child] : node->children) {
//             if (freq[child] > 1) {
//                 continue;
//             }

//             cur.emplace_back(i2s[i]);
//             ans.emplace_back(cur);
//             dfsGenAns(cur, child);
//             cur.pop_back();
//         }
//     }

// private:
//     unordered_map<string_view, int> s2i;
//     unordered_map<int, string_view> i2s;
//     unordered_map<Node*, int, NodeHash, NodeEqual> freq;
//     Node* root = new Node();
//     vector<vector<string>> ans;
//     NodeHash hashCalc;
// };

TEST(&Solution::deleteDuplicateFolder)