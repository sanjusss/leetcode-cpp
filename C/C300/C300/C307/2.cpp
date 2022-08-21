/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-21 10:44:04
 * @FilePath: \C\C300\C300\C307\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char i : num) {
            ++cnt[i - '0'];
        }

        string ans;
        char mid = 0;
        for (int i = 9; i >= 0; --i) {
            if (cnt[i] == 0) {
                continue;
            }

            if (cnt[i] % 2 == 1 && mid == 0) {
                mid = i + '0';
            }

            if (i == 0 && ans.empty()) {
                if (mid == 0) {
                    mid = '0';
                }

                continue;
            }

            for (int j = cnt[i] / 2; j > 0; --j) {
                ans.push_back(i + '0');
            }
        }

        int prefix = ans.size();
        if (mid != 0) {
            ans.push_back(mid);
        }
        
        for (int i = prefix - 1; i >= 0; --i) {
            ans.push_back(ans[i]);
        }

        return ans;
    }
};