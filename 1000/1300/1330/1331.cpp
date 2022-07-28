/*
 * @Author: sanjusss
 * @Date: 2022-07-28 08:06:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-28 08:10:17
 * @FilePath: \1000\1300\1330\1331.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> ind;
        for (int i : arr) {
            ind[i] = 0;
        }

        int j = 0;
        for (auto& [_, i] : ind) {
            i = ++j;
        }

        for (int& v : arr) {
            v = ind[v];
        }

        return arr;
    }
};