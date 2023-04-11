#include "leetcode.h"

class Solution {
public:
    bool isRobotBounded(string instructions) {
        static const vector<pair<int, int>> sc_dirs = {
            { 0, 1 },
            { 1, 0 },
            { 0, -1 },
            { -1, 0 },
        };
        int d = 0;
        int x = 0;
        int y = 0;
        for (char i : instructions) {
            if (i == 'L') {
                d = (d + 4 - 1) % 4;
            }
            else if (i == 'R') {
                d = (d + 1) % 4;
            }
            else {
                x += sc_dirs[d].first;
                y += sc_dirs[d].second;
            }
        }

        return d != 0 || (x == 0 && y == 0);
    }
};