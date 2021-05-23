/*
 * @Author: sanjusss
 * @Date: 2021-05-23 09:23:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-23 09:54:01
 * @FilePath: \1000\1700\1700\1707.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct Node {
//         // ~Node() {
//         //     delete children[0];
//         //     delete children[1];
//         // }

//         Node* children[2] = { 0 };
//     };

// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         sort(nums.begin(), nums.end());
//         int qsize = queries.size();
//         vector<int> qis(qsize);
//         iota(qis.begin(), qis.end(), 0);
//         sort(qis.begin(), qis.end(), [&queries](int a, int b) { return queries[a][1] < queries[b][1]; });

//         int ni = 0;
//         int nsize = nums.size();
//         vector<int> ans(qsize);
//         Node root;
//         for (int qi : qis) {
//             int xi = queries[qi][0];
//             int mi = queries[qi][1];
//             while (ni < nsize && nums[ni] <= mi) {
//                 int n = nums[ni];
//                 Node* node = &root;
//                 for (int i = 31; i >= 0; --i) {
//                     int bit = ((1 << i) & n) ? 1 : 0;
//                     if (node->children[bit] == nullptr) {
//                         node->children[bit] = new Node();
//                     }

//                     node = node->children[bit];
//                 }

//                 ++ni;
//             }

//             Node* node = &root;
//             int res = 0;
//             if (ni > 0) {
//                 for (int i = 31; i >= 0; --i) {
//                     int bit = ((1 << i) & xi) ? 1 : 0;
//                     if (node->children[1 - bit] != nullptr) {
//                         res |= 1 << i;
//                         node = node->children[1 - bit];
//                     }
//                     else {
//                         node = node->children[bit];
//                     }
//                 }
//             }
//             else {
//                 res = -1;
//             }

//             ans[qi] = res;
//         }

//         return ans;
//     }
// };

class Solution {
    struct Node {
        // ~Node() {
        //     delete children[0];
        //     delete children[1];
        // }

        Node* children[2] = { 0 };
        int min = INT_MAX;
    };

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Node root;
        for (int n : nums) {
            Node* node = &root;
            node->min = min(node->min, n);
            for (int i = 31; i >= 0; --i) {
                int bit = ((1 << i) & n) ? 1 : 0;
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new Node();
                }

                node = node->children[bit];
                node->min = min(node->min, n);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int x = q[0];
            int m = q[1];
            if (root.min > m) {
                ans.push_back(-1);
                continue;
            }

            Node* node = &root;
            int res = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = ((1 << i) & x) ? 1 : 0;
                if (node->children[1 - bit] != nullptr && node->children[1 - bit]->min <= m) {
                    res |= 1 << i;
                    node = node->children[1 - bit];
                }
                else {
                    node = node->children[bit];
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};

TEST(&Solution::maximizeXor)