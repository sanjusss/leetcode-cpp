/*
 * @Author: sanjusss
 * @Date: 2023-08-02 11:16:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-02 11:20:20
 * @FilePath: \0\800\820\822.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = INT_MAX;
        int n = fronts.size();
        unordered_set<int> bans;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                bans.insert(fronts[i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!bans.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }

            if (!bans.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }

        if (ans == INT_MAX) {
            return 0;
        }
        else {
            return ans;
        }
    }
};