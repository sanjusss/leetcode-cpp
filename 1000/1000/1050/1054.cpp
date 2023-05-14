/*
 * @Author: sanjusss
 * @Date: 2023-05-14 09:42:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-14 09:46:34
 * @FilePath: \1000\1000\1050\1054.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        for (int i : barcodes) {
            ++cnt[i];
        }

        priority_queue<pair<int, int>> q;
        for (auto [i, c] : cnt) {
            q.emplace(c, i);
        }

        vector<int> ans;
        while (!q.empty()) {
            auto [c, i] = q.top();
            q.pop();
            if (!ans.empty() && ans.back() == i && !q.empty()) {
                auto [c2, i2] = q.top();
                q.pop();
                ans.push_back(i2);
                if (--c2 > 0) {
                    q.emplace(c2, i2);
                }
            }

            ans.push_back(i);
            if (--c > 0) {
                q.emplace(c, i);
            }
        }

        return ans;
    }
};