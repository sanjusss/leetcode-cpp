/*
 * @Author: sanjusss
 * @Date: 2022-04-17 10:27:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-17 10:36:21
 * @FilePath: \C\C200\C280\C289\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string digitSum(string s, int k) {
        string t;
        while (s.size() > k) {
            int n = s.size();
            int cur = 0;
            for (int i = 0; i <= n; ++i) {
                if (i == n || (i > 0 && i % k == 0)) {
                    t += to_string(cur);
                    cur = 0;
                }
                
                if (i < n) {
                    cur += s[i] - '0';
                }
            }

            swap(s, t);
            t.clear();
        }

        return s;
    }
};