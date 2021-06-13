/*
 * @Author: sanjusss
 * @Date: 2021-06-13 10:25:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 11:20:11
 * @FilePath: \C\C200\C240\C245\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> hasValue(3);
        for (auto& t : triplets) {
            if (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                hasValue[0] = true;
            }

            if (t[1] == target[1] && t[0] <= target[0] && t[2] <= target[2]) {
                hasValue[1] = true;
            }

            if (t[2] == target[2] && t[1] <= target[1] && t[0] <= target[0]) {
                hasValue[2] = true;
            }
        }

        for (bool has : hasValue) {
            if (!has) {
                return false;
            }
        }

        return true;
    }
};