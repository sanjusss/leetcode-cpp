/*
 * @Author: sanjusss
 * @Date: 2023-05-19 09:17:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-19 10:22:23
 * @FilePath: \1000\1000\1070\1079.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_map<char, int> vs;
        for (char i : tiles) {
            ++vs[i];
        }

        vector<int> cnt;
        for (auto [_, c] : vs) {
            cnt.push_back(c);
        }

        int m = cnt.size();
        unordered_set<int64_t> cur;
        cur.insert(0);
        int ans = 0;
        vector<int> states(m);
        for (int i = 0; i < n; ++i) {
            unordered_set<int64_t> next;
            for (int64_t mask : cur) {
                fill(states.begin(), states.end(), 0);
                for (int64_t j = mask; j > 0; j >>= 4) {
                    ++states[(j & 0xF) - 1];
                }

                mask <<= 4;
                for (int j = 0; j < m; ++j) {
                    if (states[j] < cnt[j] && next.insert(mask + j + 1).second) {
                        ++ans;
                    }
                }
            }

            swap(cur, next);
        }

        return ans;
    }
};

TEST(&Solution::numTilePossibilities)