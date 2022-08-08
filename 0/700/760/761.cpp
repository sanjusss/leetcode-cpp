/*
 * @Author: sanjusss
 * @Date: 2022-08-08 08:42:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-08 08:50:27
 * @FilePath: \0\700\760\761.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }

        int n = s.size();
        int cnt = 0;
        int left = 0;
        vector<string> subs;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            }
            else if (--cnt == 0) {
                subs.push_back("1"s + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0"s);
                left = i + 1;
            }
        }

        sort(subs.begin(), subs.end(), greater<>());
        return accumulate(subs.begin(), subs.end(), ""s);
    }
};