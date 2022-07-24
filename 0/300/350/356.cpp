/*
 * @Author: sanjusss
 * @Date: 2022-07-14 11:55:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-14 12:05:28
 * @FilePath: \0\300\350\356.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        struct Line {
            int xMax = INT_MIN;
            int xMin = INT_MAX;
            unordered_set<int> xAll;
        };
        unordered_map<int, Line> lines;
        for (auto& p : points) {
            int x = p[0];
            int y = p[1];
            auto& line = lines[y];
            line.xMin = min(line.xMin, x);
            line.xMax = max(line.xMax, x);
            line.xAll.insert(x);
        }

        bool init = false;
        int sum = 0;
        for (auto& [_, line] : lines) {
            if (!init) {
                init = true;
                sum = line.xMin + line.xMax;
            }
            else if (sum != line.xMin + line.xMax) {
                return false;
            }

            for (int x : line.xAll) {
                if (!line.xAll.count(sum - x)) {
                    return false;
                }
            }
        }

        return true;
    }   
};