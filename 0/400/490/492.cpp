/*
 * @Author: sanjusss
 * @Date: 2021-10-23 09:26:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-23 09:28:11
 * @FilePath: \0\400\490\492.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i = sqrt(area); i > 0; --i) {
            if (area % i == 0) {
                return { area / i, i };
            }
        }

        return {};
    }
};