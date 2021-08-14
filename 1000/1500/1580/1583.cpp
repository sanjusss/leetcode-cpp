/*
 * @Author: sanjusss
 * @Date: 2021-08-14 09:19:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-14 09:34:25
 * @FilePath: \1000\1500\1580\1583.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> ref(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int r = 0;
            for (int j : preferences[i]) {
                ref[i][j] = ++r;
            }
        }

        unordered_map<int, int> pairmap;
        vector<int> pairref(n);
        for (auto& p : pairs) {
            pairmap.emplace(p[0], p[1]);
            pairref[p[0]] = ref[p[0]][p[1]];
            pairmap.emplace(p[1], p[0]);
            pairref[p[1]] = ref[p[1]][p[0]];
        }

        vector<bool> used(n);
        int ans = 0;
        for (auto [k, v] : pairmap) {
            if (used[k]) {
                continue;
            }

            used[k] = true;
            bool sad = false;
            for (int i : preferences[k]) {
                if (i == v) {
                    break;
                }

                if (ref[k][i] < pairref[k] && ref[i][k] < pairref[i]) {
                    if (!used[i]) {
                        used[i] = true;
                        ++ans;
                    }
                    
                    sad = true;
                }
            }

            if (sad) {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::unhappyFriends)