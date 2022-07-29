/*
 * @Author: sanjusss
 * @Date: 2022-07-29 08:18:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-29 08:26:14
 * @FilePath: \0\500\590\593.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2) {
            return false;
        }

        int centerX = p1[0] + p2[0] + p3[0] + p4[0];
        int centerY = p1[1] + p2[1] + p3[1] + p4[1];
        auto reset = [centerX, centerY] (const vector<int> & p) {
            return make_pair(p[0] * 4 - centerX, p[1] * 4 - centerY);
        };
        vector<pair<int, int>> pts = {
            reset(p1),
            reset(p2),
            reset(p3),
            reset(p4),
        };
        
        for (auto [x, y] : pts) {
            for (int i = 0; i < 3; ++i) {
                tie(x, y) = make_pair(-y, x);
                bool find = false;
                for (auto [tx, ty] : pts) {
                    if (x == tx && y == ty) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    return false;
                }
            }
        }

        return true;
    }
};
