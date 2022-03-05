/*
 * @Author: sanjusss
 * @Date: 2022-02-28 08:48:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-28 08:53:46
 * @FilePath: \1000\1600\1600\1601.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> builds(n);
        int ans = 0;
        int person = requests.size();
        for (int mask = (1 << person) - 1; mask > 0; --mask) {
            fill(builds.begin(), builds.end(), 0);
            for (int i = 0; i < person; ++i) {
                if (mask & (1 << i)) {
                    --builds[requests[i][0]];
                    ++builds[requests[i][1]];
                }
            }

            bool success = true;
            for (int i : builds) {
                if (i != 0) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }

        return ans;
    }
};