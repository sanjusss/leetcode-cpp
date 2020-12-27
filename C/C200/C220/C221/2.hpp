/*
 * @Author: sanjusss
 * @Date: 2020-12-27 10:36:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 10:49:13
 * @FilePath: \C\C200\C220\C221\2.hpp
 */
#include "leetcode.h"

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        map<int, int> remains;
        int ans = 0;
        int i = 0;
        while (i < n || !remains.empty()) {
            if (i < n && apples[i] > 0) {
                remains[i + days[i]] += apples[i];
            }

            while (!remains.empty() && remains.begin()->first <= i) {
                remains.erase(remains.begin());
            }

            if (!remains.empty()) {
                ++ans;
                auto begin = remains.begin();
                --(begin->second);
                if (begin->second == 0) {
                    remains.erase(begin);
                }
            }

            ++i;
        }

        return ans;
    }
};