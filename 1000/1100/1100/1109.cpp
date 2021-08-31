/*
 * @Author: sanjusss
 * @Date: 2021-08-31 08:24:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-31 08:48:58
 * @FilePath: \1000\1100\1100\1109.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct TreeArray {
//         TreeArray(int n) : n(n), tree(n * 4) {
//         }

//         int query(int i) {
//             return query(i, i, 0, n - 1, 1);
//         }

//         int query(int ql, int qr, int cl, int cr, int i) {
//             if (i >= tree.size() || ql > cr || qr < cl) {
//                 return 0;
//             }

//             pull(cl, cr, i);
//             if (cl >= ql && cr <= qr) {
//                 return tree[i];
//             }

//             int mid = (cl + cr) / 2;
//             return query(ql, qr, cl, mid, i * 2) + query(ql, qr, mid + 1, cr, i * 2 + 1);
//         }

//         void add(int left, int right, int val) {
//             add(left, right, 0, n - 1, 1, val);
//         }

//         void add(int ql, int qr, int cl, int cr, int i, int val) {
//             if (i >= tree.size() || ql > cr || qr < cl) {
//                 return;
//             }

//             if (cl >= ql && cr <= qr) {
//                 tree[i] += val;
//                 return;
//             }

//             int mid = (cl + cr) / 2;
//             add(ql, qr, cl, mid, i * 2, val);
//             add(ql, qr, mid + 1, cr, i * 2 + 1, val);
//         }

//         void pull(int left, int right, int i) {
//             if (left == right) {
//                 return;
//             }

//             tree[i * 2] += tree[i];
//             tree[i * 2 + 1] += tree[i];
//             tree[i] = 0;
//         }

//         const int n;
//         vector<int> tree;
//     };

// public:
//     vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//         TreeArray ta(n);
//         for (auto& b : bookings) {
//             ta.add(b[0] - 1, b[1] - 1, b[2]);
//         }

//         vector<int> ans;
//         for (int i = 0; i < n; ++i) {
//             ans.push_back(ta.query(i));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& b : bookings) {
            ans[b[0] - 1] += b[2];
            if (b[1] < n) {
                ans[b[1]] -= b[2];
            }
        }

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += ans[i];
            ans[i] = cur;
        }

        return ans;
    }
};

TEST(&Solution::corpFlightBookings)