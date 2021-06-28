/*
 * @Author: sanjusss
 * @Date: 2021-06-28 09:37:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-28 10:45:23
 * @FilePath: \D\D000\D55\2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int n = s.size();
//         int m = part.size();
//         vector<int> nexts(n + 1);
//         nexts[n] = -1; 
//         for (int i = 0; i < n; ++i) {
//             nexts[i] = i + 1;
//         }

//         bool find = false;
//         do {
//             find = false;
//             int prev = 0;
//             int cur = nexts[0];
//             while (cur > 0) {
//                 int c = cur;
//                 int i = 0;
//                 while (c > 0 && i < m && s[c - 1] == part[i]) {
//                     c = nexts[c];
//                     ++i;
//                 }

//                 if (i == m) { //匹配成功
//                     nexts[prev] = c;
//                     find = true;
//                     break;
//                 }
//                 else { //匹配失败
//                     prev = cur;
//                     cur = nexts[cur];
//                 }
//             }
//         } while (find);

//         int len = 0;
//         int cur = nexts[0];
//         while (cur > 0) {
//             s[len++] = s[cur - 1];
//             cur = nexts[cur];
//         }

//         s.resize(len);
//         return move(s);
//     }
// };

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        string_view svp = part;
        string ans;
        ans.reserve(s.size());
        for (char i : s) {
            ans.push_back(i);
            int n = ans.size();
            if (n < m || string_view(ans).substr(n - m, m) != svp) {
                continue;
            }
            
            for (int j = 0; j < m; ++j) {
                ans.pop_back();
            }
        }

        return ans;
    }
};

TEST(&Solution::removeOccurrences)