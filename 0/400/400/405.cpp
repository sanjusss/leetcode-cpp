/*
 * @Author: sanjusss
 * @Date: 2021-10-02 12:49:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-02 13:01:19
 * @FilePath: \0\400\400\405.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string toHex(int num) {
        int64_t n = num;
        if (n < 0) {
            n = ((-n) ^ (int64_t)(UINT32_MAX)) + 1;
        }

        string ans;
        while (n) {
            int i = n % 16;
            n /= 16;
            if (i < 10) {
                ans.push_back('0' + i);
            }
            else {
                ans.push_back('a' + i - 10);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0"s : ans;
    }
};

TEST(&Solution::toHex)