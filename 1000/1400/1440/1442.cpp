/*
 * @Author: sanjusss
 * @Date: 2021-05-18 08:36:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-18 09:11:07
 * @FilePath: \1000\1400\1440\1442.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> xors(n + 1);
//         for (int i = 0; i < n; ++i) {
//             xors[i + 1] = xors[i] ^ arr[i];
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int a = xors[j] ^ xors[i];
//                 for (int k = j; k < n; ++k) {
//                     int b = xors[j] ^ xors[k + 1];
//                     if (a == b) {
//                         ++ans;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> xors(n + 1);
//         for (int i = 0; i < n; ++i) {
//             xors[i + 1] = xors[i] ^ arr[i];
//         }

//         vector<unordered_map<int, int>> cnts(n);
//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 ++cnts[i][xors[i] ^ xors[j + 1]];
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 auto p = cnts[j].find(xors[i] ^ xors[j]);
//                 if (p != cnts[j].end()) {
//                     ans += p->second;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> cnt;
        unordered_map<int, int> total;
        int xors = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            ans += i * cnt[xors ^ arr[i]] - total[xors ^ arr[i]];

            ++cnt[xors];
            total[xors] += i;
            xors ^= arr[i];
        }

        return ans;
    }
};

TEST(&Solution::countTriplets)