/*
 * @Author: sanjusss
 * @Date: 2021-07-29 17:08:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-29 17:20:05
 * @FilePath: \1000\1100\1100\1104.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int cur = 1;
        bool left2Right = false;
        while (cur <= label) {
            left2Right = !left2Right;
            cur *= 2;
        }

        vector<int> ans({ label });
        int pos;
        if (left2Right) {
            pos = label - cur / 2;
        }
        else {
            pos = cur - 1 - label;
        }

        while (cur > 2) {
            cur /= 2;
            pos /= 2;
            left2Right = !left2Right;
            if (left2Right) {
                ans.push_back(cur / 2 + pos);
            }
            else {
                ans.push_back(cur - 1 - pos);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

TEST(&Solution::pathInZigZagTree)