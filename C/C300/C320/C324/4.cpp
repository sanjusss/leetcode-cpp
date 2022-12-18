/*
 * @Author: sanjusss
 * @Date: 2022-12-18 10:24:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-18 11:03:32
 * @FilePath: \C\C300\C320\C324\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0];
            int b = q[1];
            int res = 1;
            while (a != b) {
                if (a > b) {
                    swap(a, b);
                }

                b /= 2;
                ++res;
                if (a > b) {
                    a /= 2;
                    ++res;
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};