/*
 * @Author: sanjusss
 * @Date: 2021-06-29 08:27:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-29 08:39:46
 * @FilePath: \0\100\160\168.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         string ans;
//         while (columnNumber > 0) {
//             int remain;
//             if (columnNumber % 26 == 0) {
//                 ans.push_back('Z');
//                 remain = -1;
//             }
//             else {
//                 ans.push_back('A' - 1 + (columnNumber % 26));
//                 remain = 0;
//             }

//             columnNumber /= 26;
//             columnNumber += remain;
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (--columnNumber >= 0) {
            ans.push_back('A' + (columnNumber % 26));
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

TEST(&Solution::convertToTitle)