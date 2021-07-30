/*
 * @Author: sanjusss
 * @Date: 2021-07-30 08:29:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-30 08:33:24
 * @FilePath: \chengxuyuanmianshijindian\0101.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isUnique(string astr) {
//         array<bool, 26> contains{ };
//         for (char i : astr) {
//             if (contains[i - 'a']) {
//                 return false;
//             }
//             else {
//                 contains[i - 'a'] = true;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26) {
            return false;
        }

        sort(astr.begin(), astr.end());
        for (int i = 1; i < astr.size(); ++i) {
            if (astr[i] == astr[i - 1]) {
                return false;
            }
        }

        return true;
    }
};

TEST(&Solution::isUnique)