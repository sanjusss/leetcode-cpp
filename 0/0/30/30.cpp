/*
 * @Author: sanjusss
 * @Date: 2021-05-27 08:35:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-27 09:44:55
 * @FilePath: \0\0\30\30.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct Node {
//         ~Node() {
//             for (auto i : children) {
//                 delete i;
//             }
//         }
        
//         array<Node*, 26> children = { 0 };
//         int cnt = 0;
//     };
    
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int wsize = words[0].size();
//         int wn = words.size();
//         int length = wsize * wn;
//         Node root;
//         unordered_map<Node*, int> cnt;
//         for (auto& w : words) {
//             Node* node = &root;
//             for (char i : w) {
//                 if (node->children[i - 'a'] == nullptr) {
//                     node->children[i - 'a'] = new Node();
//                 }

//                 node = node->children[i - 'a'];
//             }

//             ++(node->cnt);
//             ++cnt[node];
//         }

//         vector<int> ans;
//         int ssize = s.size();
//         for (int i = 0; i <= ssize - length; ++i) {
//             for (auto& [node, c] : cnt) {
//                 node->cnt = c;
//             }

//             bool success = true;
//             int j = i;
//             for (int k = 0; k < wn && success; ++k) {
//                 Node* node = &root;
//                 for (int l = 0; l < wsize && node != nullptr; ++l) {
//                     node = node->children[s[j++] - 'a'];
//                 }

//                 if (node == nullptr || --(node->cnt) < 0) {
//                     success = false;
//                 }
//             }

//             if (success) {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wsize = words[0].size();
        int wn = words.size();
        int length = wsize * wn;
        string_view sv = s;
        unordered_map<string_view, int> cnt;
        for (auto& w : words) {
            ++cnt[w];
        }

        vector<int> ans;
        int end = sv.size();
        for (int begin = 0; begin < wsize; ++begin) {
            unordered_map<string_view, int> curCnt;
            int successCount = 0;
            int count = 0;
            for (int i = begin; i < end; i += wsize) {
                if (count == wn) {
                    --count;
                    string_view prev = sv.substr(i - length, wsize);
                    if (--curCnt[prev] < cnt[prev]) {
                        --successCount;
                    }
                }

                string_view cur = sv.substr(i, wsize);
                auto pSrc = cnt.find(cur);
                if (pSrc == cnt.end()) {
                    curCnt.clear();
                    count = 0;
                    successCount = 0;
                }
                else {
                    ++count;
                    if (++curCnt[cur] <= pSrc->second) {
                        ++successCount;
                    }
                }

                if (successCount == wn) {
                    ans.push_back(i + wsize - length);
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findSubstring)