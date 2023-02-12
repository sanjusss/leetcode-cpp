/*
 * @Author: sanjusss
 * @Date: 2023-02-12 13:04:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-12 13:21:56
 * @FilePath: \1000\1100\1130\1138.cpp
 */
#include "leetcode.h"

static vector<vector<string>> path(26, vector<string>(26));
static int init = []() {
    vector<tuple<int, int, char>> dirs = {
        { 1, 0, 'D' },
        { -1, 0, 'U' },
        { 0, -1, 'L' },
        { 0, 1, 'R' },
    };
    queue<tuple<int, int, string>> q;
    for (int i = 0; i < 26; ++i) {
        q.emplace(i / 5, i % 5, string());
        while (!q.empty()) {
            auto [j, k, p] = q.front();
            q.pop();
            for (auto [dx, dy, c] : dirs) {
                int x = j + dx;
                int y = k + dy;
                if (x < 0 || x > 5 || y < 0 || y >= 5) {
                    continue;
                }

                if (x == 5 && y != 0) {
                    continue;
                }

                int v = x * 5 + y;
                if (v == i || !path[i][v].empty()) {
                    continue;
                }

                string next = p + c;
                path[i][v] = next;
                q.emplace(x, y, next);
            }
        }
    }

    return 0;
}();

class Solution {
public:
    string alphabetBoardPath(string target) {
        int pre = 0;
        string ans;
        for (char t : target) {
            int i = t - 'a';
            ans += path[pre][i];
            ans.push_back('!');
            pre = i;
        }

        return ans;
    }
};