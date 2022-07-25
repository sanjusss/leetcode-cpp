/*
 * @Author: sanjusss
 * @Date: 2022-07-25 09:05:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-25 09:11:42
 * @FilePath: \jianzhioffer2\115.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> in(n + 1);
        vector<unordered_set<int>> out(n + 1);
        for (auto& seq : sequences) {
            int m = seq.size();
            for (int i = 1; i < m; ++i) {
                if (out[seq[i - 1]].insert(seq[i]).second) {
                    ++in[seq[i]];
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            if (q.size() != 1) {
                return false;
            }

            int i = q.front();
            q.pop();
            for (int j : out[i]) {
                if (--in[j] == 0) {
                    q.push(j);
                }
            }
        }

        return true;
    }
};