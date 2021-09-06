/*
 * @Author: sanjusss
 * @Date: 2021-09-06 08:25:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-06 09:46:57
 * @FilePath: \LCP\000\00\03.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int u = 0;
        int r = 0;
        unordered_map<int, int> passIndex = { { 0, 0 } };
        int index = 0;
        for (char c : command) {
            if (c == 'U') {
                ++u;
            }
            else {
                ++r;
            }

            passIndex[(r << 16) | u] = ++index;
        }

        int xt = x / r;
        int yt = y / u;
        if (r != 0 && u != 0 && abs(xt - yt) > 1) {
            return false;
        }

        x = x % r + (xt > yt ? r : 0);
        y = y % u + (yt > xt ? u : 0);
        if (passIndex.count((x << 16) | y) == 0) {
            return false;
        }

        int tIndex = passIndex[(x << 16) | y];

        for (auto& o : obstacles) {
            int i = o[0];
            int j = o[1];
            int it = i / r;
            int jt = j / u;
            if (r != 0 && u != 0 && abs(it - jt) > 1) {
                continue;
            }

            if (it > xt || jt > yt) {
                continue;
            }

            i = i % r + (it > jt ? r : 0);
            j = j % u + (jt > it ? u : 0);
            if (passIndex.count((i << 16) | j) == 0) {
                continue;
            }

            if (it < xt || jt < yt) {
                return false;
            }

            int index = passIndex[(i << 16) | j];
            if (index <= tIndex) {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::robot)