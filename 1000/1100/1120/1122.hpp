/*
 * @Author: sanjusss
 * @Date: 2020-11-14 16:52:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-14 17:17:27
 * @FilePath: \1000\1100\1120\1122.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         map<int, int> cnt;
//         for (int i : arr1) {
//             ++cnt[i];
//         }

//         vector<int> ans;
//         for (int i : arr2) {
//             auto pos = cnt.find(i);
//             if (pos == cnt.end()) {
//                 continue;
//             }

//             for (int j = 0; j < pos->second; ++j) {
//                 ans.push_back(i);
//             }

//             cnt.erase(pos);
//         }

//         for (auto& p : cnt) {
//             for (int i = 0; i < p.second; ++i) {
//                 ans.push_back(p.first);
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         unordered_map<int, int> positions;
//         for (int i = 0; i < arr2.size(); ++i) {
//             positions[arr2[i]] = i;
//         }

//         sort(arr1.begin(), arr1.end(), [&positions](int a, int b) {
//             auto pa = positions.find(a);
//             auto pb = positions.find(b);
//             if (pa != positions.end() || pb != positions.end()) {
//                 if (pa != positions.end() && pb != positions.end()) {
//                     return pa->second < pb->second;
//                 }
//                 else {
//                     return pb == positions.end();
//                 }
//             }
//             else {
//                 return a < b;
//             }
//         });
//         return arr1;
//     }
// };

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> cnt(maxElement + 1);
        for (int i : arr1) {
            ++cnt[i];
        }

        vector<int> ans;
        for (int i : arr2) {
            for (int j = cnt[i]; j > 0; --j) {
                ans.push_back(i);
            }

            cnt[i] = 0;
        }

        for (int i = 0; i <= maxElement; ++i) {
            for (int j = cnt[i]; j > 0; --j) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};