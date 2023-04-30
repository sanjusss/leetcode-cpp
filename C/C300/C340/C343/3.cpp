/*
 * @Author: sanjusss
 * @Date: 2023-04-30 10:27:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-30 11:03:06
 * @FilePath: \C\C300\C340\C343\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        vector<int> costs(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, start[0], start[1]);
        while (!q.empty()) {
            auto [c, i, j] = q.top();
            q.pop();
            if (i == target[0] && j == target[1]) {
                return c;
            }

            for (int k = 0; k < n; ++k) {
                auto& s = specialRoads[k];
                int next = c + abs(s[0] - i) + abs(s[1] - j) + s[4];
                if (next >= costs[k]) {
                    continue;
                }

                costs[k] = next;
                q.emplace(next, s[2], s[3]);
            }

            q.emplace(c + abs(target[0] - i) + abs(target[1] - j), target[0], target[1]);
        }

        return -1;
    }
};

TEST(&Solution::minimumCost)