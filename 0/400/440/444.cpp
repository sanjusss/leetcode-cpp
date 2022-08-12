/*
 * @Author: sanjusss
 * @Date: 2022-08-12 08:19:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-12 08:56:56
 * @FilePath: \0\400\440\444.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
//         int n = nums.size();
//         vector<int> nexts(n + 1);
//         for (int i = 1; i < n; ++i) {
//             nexts[nums[i - 1]] = nums[i];
//         }

//         vector<bool> validNexts(n + 1);
//         for (auto& seq : sequences) {
//             for (int i = seq.size() - 1; i > 0; --i) {
//                 if (nexts[seq[i - 1]] == seq[i]) {
//                     validNexts[seq[i - 1]] = true;
//                 }
//             }
//         }

//         int cnt = 0;
//         for (auto i : validNexts) {
//             if (!i) {
//                 ++cnt;
//             }
//         }

//         return cnt == 2;
//     }
// };

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> ins(n + 1);
        vector<unordered_set<int>> outs(n + 1);
        for (auto& seq : sequences) {
            for (int i = seq.size() - 1; i > 0; --i) {
                if (outs[seq[i - 1]].insert(seq[i]).second) {
                    ++ins[seq[i]];
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (ins[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            if (q.size() != 1) {
                return false;
            }

            int i = q.front();
            q.pop();
            for (int j : outs[i]) {
                if (--ins[j] == 0) {
                    q.push(j);
                }
            }
        }

        return true;
    }
};