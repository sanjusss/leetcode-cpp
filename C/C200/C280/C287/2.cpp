/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:19:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 10:36:54
 * @FilePath: \C\C200\C280\C287\2.cpp
 */
/*
 * @Author: sanjusss
 * @Date: 2022-04-03 10:19:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-03 10:19:10
 * @FilePath: \C\C200\C280\C287\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loses;
        for (auto& m : matches) {
            loses[m[0]] += 0;
            loses[m[1]] += 1;
        }

        vector<vector<int>> ans(2);
        for (auto [i, c] : loses) {
            if (c == 0) {
                ans[0].push_back(i);
            }
            else if (c == 1) {
                ans[1].push_back(i);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};