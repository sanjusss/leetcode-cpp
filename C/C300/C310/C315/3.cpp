/*
 * @Author: sanjusss
 * @Date: 2022-10-16 10:35:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-16 10:44:38
 * @FilePath: \C\C300\C310\C315\3.cpp
 */
#include "leetcode.h"

static vector<int> rs;
static constexpr int maxI = 1e5;
static int init = []() {
    rs.resize(maxI + 1);
    for (int i = 1; i <= maxI; ++i) {
        int v = 0;
        int b = i;
        while (b > 0) {
            v = v * 10 + b % 10;
            b /= 10;
        }

        rs[i] = v;
    }

    return 0;
}();

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= maxI; ++i) {
            if (i + rs[i] == num) {
                return true;
            }
        }

        return false;
    }
};