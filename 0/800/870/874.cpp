#include "leetcode.h"

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        static const vector<pair<int, int>> dirs = {
            { 0, 1 },
            { 1, 0 },
            { 0, -1 },
            { -1, 0 },
        };
        unordered_map<int, unordered_set<int>> invalids;
        for (auto& ob : obstacles) {
            invalids[ob[0]].insert(ob[1]);
        }

        int ans = 0;
        int d = 0;
        int i = 0;
        int j = 0;
        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
                continue;
            }
            else if (c == -1) {
                d = (d + 1) % 4;
                continue;
            }

            auto [dx, dy] = dirs[d];
            while (c > 0) {
                int x = i + dx;
                int y = j + dy;
                if (invalids.count(x) && invalids[x].count(y)) {
                    break;
                }

                i = x;
                j = y;
                --c;
            }

            ans = max(ans, i * i + j * j);
        }

        return ans;
    }
};