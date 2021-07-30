/*
 * @Author: sanjusss
 * @Date: 2021-07-30 08:41:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-30 08:46:47
 * @FilePath: \chengxuyuanmianshijindian\0102.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
//         sort(s1.begin(), s1.end());
//         sort(s2.begin(), s2.end());
//         return s1 == s2;
//     }
// };

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> cnt;
        for (char i : s1) {
            ++cnt[i];
        }

        for (char i : s2) {
            --cnt[i];
        }

        for (auto [_, i] : cnt) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }
};