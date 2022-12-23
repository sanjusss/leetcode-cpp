/*
 * @Author: sanjusss
 * @Date: 2022-12-23 08:28:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-23 08:28:38
 * @FilePath: \2000\2000\2010\2011.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& op : operations) {
            if (op[1] == '+') {
                ++ans;
            }
            else {
                --ans;
            }
        }

        return ans;
    }
};