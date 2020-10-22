#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> partitionLabels(string S) {
//         int size = S.size();
//         unordered_map<int, pair<int, int>> ranges;
//         for (int i = 0; i < size; ++i) {
//             auto pos = ranges.find(S[i]);
//             if (pos == ranges.end()) {
//                 ranges[S[i]] = { i, i };
//             }
//             else {
//                 pos->second.second = i;
//             }
//         }

//         map<int, int> bs;
//         for (auto& i : ranges) {
//             bs.insert(i.second);
//         }

//         vector<int> ans;
//         int i = 0;
//         while (i < size) {
//             int start = i;
//             int prev = i - 1;
//             auto cur = bs.find(i);
//             while (true) {
//                 auto begin = bs.upper_bound(prev);
//                 auto end = bs.upper_bound(cur->second);
//                 auto next = cur;
//                 for (auto j = begin; j != end; ++j) {
//                     if (j->second > next->second) {
//                         next = j;
//                     }
//                 }

//                 if (next->first == cur->first) {
//                     break;
//                 }
//                 else {
//                     prev = cur->second;
//                     cur = next;
//                 }
//             }

//             ans.push_back(cur->second - start + 1);
//             i = cur->second + 1;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size = S.size();
        array<int, 26> ends = { 0 };
        for (int i = 0; i < size; ++i) {
            ends[S[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < size; ++i) {
            end = max(end, ends[S[i] - 'a']);
            if (end == i) {
                ans.push_back(end + 1 - start);
                start = i + 1;
            }
        }

        return ans;
    }
};