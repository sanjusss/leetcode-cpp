/*
 * @Author: sanjusss
 * @Date: 2022-10-09 10:18:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-09 11:50:03
 * @FilePath: \0\800\850\856.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         stack<int> sc;
//         sc.push(0);
//         char prev = 0;
//         for (char i : s) {
//             if (i == ')') {
//                 int cur = sc.top();
//                 sc.pop();
//                 if (prev == '(') {
//                     cur += 1;
//                 }
//                 else {
//                     cur *= 2;
//                 }

//                 sc.top() += cur;
//             }
//             else {
//                 sc.push(0);
//             }

//             prev = i;
//         }

//         return sc.top();
//     }
// };

class Solution {
public:
    int scoreOfParentheses(string s) {
        char prev = 0;
        int depth = 0;
        int ans = 0;
        for (char i : s) {
            if (i == '(') {
                ++depth;
            }
            else {
                --depth;
                if (prev == '(') {
                    ans += 1 << depth;
                }
            }

            prev = i;
        }

        return ans;
    }
};