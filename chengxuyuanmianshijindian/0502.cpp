/*
 * @Author: sanjusss
 * @Date: 2023-03-02 09:07:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-02 09:19:54
 * @FilePath: \chengxuyuanmianshijindian\0502.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string printBin(double num) {
        string ans = "0."s;
        int base = 1e6 / 2;
        int n = num * 1e6;
        while (n > 0) {
            if (n >= base) {
                n -= base;
                ans.push_back('1');
            }
            else {
                ans.push_back('0');
            }

            if (base % 2 == 1 && n > 0) {
                return "ERROR"s;
            }

            base /= 2;
        }

        while (ans.back() == '0') {
            ans.pop_back();
        }

        if (ans.back() == '.') {
            ans.push_back('0');
        }

        return ans.size() > 32 ? "ERROR"s : ans;
    }
};