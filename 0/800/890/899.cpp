/*
 * @Author: sanjusss
 * @Date: 2022-08-03 08:42:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-03 09:22:54
 * @FilePath: \0\800\890\899.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string orderlyQueue(string s, int k) {
//         if (k > 1) {
//             sort(s.begin(), s.end());
//             return s;
//         }

//         string ans = s;
//         deque<char> dq(s.begin(), s.end());
//         int n = s.size();
//         for (int i = 1; i < n; ++i) {
//             dq.push_back(dq.front());
//             dq.pop_front();
//             if (lexicographical_compare(dq.begin(), dq.end(), ans.begin(), ans.end())) {
//                 ans = string(dq.begin(), dq.end());
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        int n = s.size();
        int i = 0;
        int j = 1;
        k = 0;
        while (k < n && i < n && j < n) {
            if (s[(i + k) % n] == s[(j + k) % n]) {
                ++k;
            }
            else {
                if (s[(i + k) % n] > s[(j + k) % n]) {
                    i += k + 1;
                }
                else {
                    j += k + 1;
                }

                k = 0;
                if (i == j) {
                    ++j;
                }
            } 
        }

        int p = min(i, j);
        return s.substr(p) + s.substr(0, p);
    }
};