/*
 * @Author: sanjusss
 * @Date: 2022-08-11 08:56:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-11 10:35:56
 * @FilePath: \0\400\430\439.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string parseTernary(string expression) {
//         return ""s + parse(expression);
//     }

// private:
//     char parse(string_view e) {
//         if (e.size() == 1) {
//             return e[0];
//         }

//         int cnt = 0;
//         int n = e.size();
//         int p = 0;
//         for (int i = 0; i < n; ++i) {
//             if (e[i] == '?') {
//                 ++cnt;
//             }
//             else if (e[i] == ':') {
//                 if (--cnt == 0) {
//                     p = i;
//                     break;
//                 }
//             }
//         }

//         if (e[0] == 'T') {
//             return parse(e.substr(2, p - 2));
//         }
//         else {
//             return parse(e.substr(p + 1));
//         }
//     }
// };

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> bs;
        int n = expression.size();
        for (int i = n - 1; i >= 0; i -= 2) {
            if (i + 1 < n && expression[i + 1] == '?') {
                if (expression[i] == 'T') {
                    char v = bs.top();
                    bs.pop();
                    bs.pop();
                    bs.push(v);
                }
                else {
                    bs.pop();
                }
            }
            else {
                bs.push(expression[i]);
            }
        }

        return ""s + bs.top();
    }
};