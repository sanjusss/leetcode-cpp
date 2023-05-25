/*
 * @Author: sanjusss
 * @Date: 2023-05-25 08:47:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-25 08:53:54
 * @FilePath: \2000\2400\2450\2451.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string oddString(vector<string>& words) {
        string t1;
        string t2;
        int t1cnt = 0;
        auto cmp = [](const string& a, const string& b) -> bool {
            if (a.size() != b.size()) {
                return false;
            }

            int n = a.size();
            for (int i = 1; i < n; ++i) {
                if (a[i] - a[i - 1] != b[i] - b[i - 1]) {
                    return false;
                }
            }

            return true;
        };
        for (auto& s : words) {
            if (t1cnt == 0) {
                ++t1cnt;
                t1 = s;
                continue;
            }

            if (cmp(t1, s)) {
                ++t1cnt;
                if (t2.empty() == false) {
                    return t2;
                }
            }
            else {
                if (t2.empty()) {
                    t2 = s;
                }
                else {
                    return t1;
                }
            }
        }

        return t2;
    }
};