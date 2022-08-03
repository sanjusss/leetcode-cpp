/*
 * @Author: sanjusss
 * @Date: 2022-08-03 08:42:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-03 09:02:30
 * @FilePath: \0\800\890\899.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        deque<char> dq(s.begin(), s.end());
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            dq.push_back(dq.front());
            dq.pop_front();
            if (lexicographical_compare(dq.begin(), dq.end(), ans.begin(), ans.end())) {
                ans = string(dq.begin(), dq.end());
            }
        }

        return ans;
    }
};