/*
 * @Author: sanjusss
 * @Date: 2023-07-18 08:02:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-18 15:54:12
 * @FilePath: \1000\1800\1850\1851.cpp
 */
#include "leetcode.h"

// class Tree {
// public:
//     struct Node {
//         Node* leftChild = nullptr;
//         Node* rightChild = nullptr;
//         int left = 0;
//         int right = 0;
//         int val = INT_MAX;
//         bool modify = false;
//     };

//     void update(int left, int right, int val) {
//         initRoot(right);
//         update(m_root, left, right, val);
//     }

//     int query(int pos) {
//         return query(m_root, pos);
//     }

// private:
//     void initRoot(int right) {
//         while (m_root->right < right) {
//             Node* node = new Node();
//             node->right = (m_root->right + 1) * 2 - 1;
//             node->leftChild = m_root;
//             m_root = node;
//         }
//     }

//     void update(Node* node, int left, int right, int val) {
//         if (node->right < left || node->left > right) {
//             return;
//         }
//         else if (left <= node->left && node->right <= right) {
//             node->val = min(node->val, val);
//             node->modify = true;
//             return;
//         }

//         if (node->leftChild == nullptr) {
//             Node* child = new Node();
//             child->left = node->left;
//             child->right = (node->left + node->right) / 2;
//             node->leftChild = child;
//         }

//         if (node->rightChild == nullptr) {
//             Node* child = new Node();
//             child->left = (node->left + node->right) / 2 + 1;
//             child->right = node->right;
//             node->rightChild = child;
//         }

//         update(node->leftChild, left, right, val);
//         update(node->rightChild, left, right, val);
//     }

//     int query(Node* node, int pos) {
//         if (pos < node->left || node->right < pos) {
//             return INT_MAX;
//         }

//         if (node->leftChild == nullptr || node->rightChild == nullptr) {
//             return node->val;
//         }

//         if (node->modify) {
//             node->modify = false;
//             node->leftChild->modify = true;
//             node->leftChild->val = min(node->leftChild->val, node->val);
//             node->rightChild->modify = true;
//             node->rightChild->val = min(node->rightChild->val, node->val);
//         }

//         if (pos <= node->leftChild->right) {
//             return query(node->leftChild, pos);
//         }
//         else {
//             return query(node->rightChild, pos);
//         }
//     }

// private:
//     Node* m_root = new Node();
// };

// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         map<int, int> v2i;
//         for (auto& in : intervals) {
//             v2i[in[0]];
//             v2i[in[1]];
//         }

//         for (auto& q : queries) {
//             v2i[q];
//         }

//         int index = 0;
//         for (auto& [_, i] : v2i) {
//             i = index++;
//         }

//         Tree tree;
//         for (auto& in : intervals) {
//             tree.update(v2i[in[0]], v2i[in[1]], in[1] - in[0] + 1);
//         }

//         vector<int> ans;
//         for (auto& q : queries) {
//             int a = tree.query(v2i[q]);
//             if (a == INT_MAX) {
//                 a = -1;
//             }

//             ans.push_back(a);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        int n = queries.size();
        vector<int> qis(n);
        iota(qis.begin(), qis.end(), 0);
        sort(qis.begin(), qis.end(), [&queries](int a, int b) { return queries[a] < queries[b]; });
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second - a.first > b.second - b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<int> ans(n);
        int mi = 0;
        for (int i : qis) {
            int q = queries[i];
            while (mi < m && q >= intervals[mi][0]) {
                pq.emplace(intervals[mi][0], intervals[mi][1]);
                ++mi;
            }

            while (!pq.empty() && q > pq.top().second) {
                pq.pop();
            }

            if (pq.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = pq.top().second - pq.top().first + 1;
            }
        }

        return ans;
    }
};

TEST(&Solution::minInterval)