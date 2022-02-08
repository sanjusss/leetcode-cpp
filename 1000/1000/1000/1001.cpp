/*
 * @Author: sanjusss
 * @Date: 2022-02-08 11:01:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-08 11:24:44
 * @FilePath: \1000\1000\1000\1001.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        static const auto sub = [](unordered_map<int64_t, int>& cnt, int64_t key) {
            auto p = cnt.find(key);
            if (p != cnt.end() && --p->second == 0) {
                cnt.erase(p);
            }
        };

        unordered_map<int64_t, int> rows;
        unordered_map<int64_t, int> cols;
        unordered_map<int64_t, int> sums;
        unordered_map<int64_t, int> diffs;
        unordered_set<int64_t> lights;
        for (auto& l : lamps) {
            int64_t x = l[0];
            int64_t y = l[1];
            if (lights.insert((x << 32) | y).second == false) {
                continue;
            }

            ++rows[x];
            ++cols[y];
            ++sums[x + y];
            ++diffs[x - y];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int64_t x = q[0];
            int64_t y = q[1];
            if (rows.count(x) || cols.count(y) || sums.count(x + y) || diffs.count(x - y)) {
                ans.push_back(1);
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int64_t cx = x + i;
                        int64_t cy = y + j;
                        if (cx < 0 || cy < 0 || !(lights.erase((cx << 32) | cy))) {
                            continue;
                        }

                        sub(rows, cx);
                        sub(cols, cy);
                        sub(sums, cx + cy);
                        sub(diffs, cx - cy);
                    }
                }
            }
            else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};