/*
 * @Author: sanjusss
 * @Date: 2021-09-12 19:27:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-12 19:45:07
 * @FilePath: \0\600\670\678.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<int> left;
//         stack<int> star;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '(') {
//                 left.push(i);
//             }
//             else if (s[i] == '*') {
//                 star.push(i);
//             }
//             else if (!left.empty()) {
//                 left.pop();
//             }
//             else if (!star.empty()) {
//                 star.pop();
//             }
//             else {
//                 return false;
//             }
//         }

//         while (!left.empty() && !star.empty() && star.top() > left.top()) {
//             star.pop();
//             left.pop();
//         }

//         return left.empty();
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        for (char i : s) {
            if (i == ')') {
                if (--left < 0) {
                    return false;
                }
            }
            else {
                ++left;
            }
        }

        int right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                if (--right < 0) {
                    return false;
                } 
            }
            else {
                ++right;
            }
        }

        return true;
    }
};

TEST(&Solution::checkValidString)