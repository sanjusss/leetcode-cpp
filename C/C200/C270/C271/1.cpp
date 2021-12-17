/*
 * @Author: sanjusss
 * @Date: 2021-12-12 10:25:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-12 10:36:14
 * @FilePath: \C\C200\C270\C271\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> has(10, vector<bool>(3));
        for (int i = 0; i < rings.size(); i += 2) {
            switch (rings[i]) {
                case 'R':
                    has[rings[i + 1] - '0'][0] = true;
                    break;
                case 'G':
                    has[rings[i + 1] - '0'][1] = true;
                    break;
                case 'B':
                    has[rings[i + 1] - '0'][2] = true;
                    break;

                default:
                    break;
            }
        }

        int ans = 0;
        for (auto& a : has) {
            bool success = true;
            for (bool i : a) {
                success = success && i;
            }

            if (success) {
                ++ans;
            }
        }

        return ans;
    }
};