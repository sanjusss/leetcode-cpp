/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 10:46:45
 * @FilePath: \C\C300\C320\C322\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<unordered_map<int, int>> conns(n + 1);
        for (auto& r : roads) {
            conns[r[0]][r[1]] = r[2];
            conns[r[1]][r[0]] = r[2];
        }

        int ans = INT_MAX;
        vector<bool> pass(n + 1);
        pass[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto [j, d] : conns[i]) {
                ans = min(ans, d);
                if (pass[j]) {
                    continue;
                }

                pass[j] = true;
                q.push(j);
            }
        }

        return ans;
    }
};

TEST(&Solution::minScore)