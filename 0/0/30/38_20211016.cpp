/*
 * @Author: sanjusss
 * @Date: 2021-10-16 11:34:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-16 11:39:15
 * @FilePath: \0\0\30\38_20211016.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1"s;
        for (int i = 2; i <= n; ++i) {
            string next;
            int size = ans.size();
            int cnt = 1;
            for (int j = 1; j <= size; ++j) {
                if (j == size || ans[j] != ans[j - 1]) {
                    next += to_string(cnt) + ans[j - 1];
                    cnt = 1;
                }
                else {
                    ++cnt;
                }
            }

            ans = move(next);
        }

        return ans;
    }
};