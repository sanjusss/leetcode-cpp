/*
 * @Author: sanjusss
 * @Date: 2022-03-31 10:49:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-31 10:59:11
 * @FilePath: \0\700\720\728.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            int n = i;
            bool success = true;
            while (n > 0) {
                int j = n % 10;
                if (j != 0 && i % j == 0) {
                    n /= 10;
                }
                else {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};