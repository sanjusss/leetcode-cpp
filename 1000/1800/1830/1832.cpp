/*
 * @Author: sanjusss
 * @Date: 2022-12-13 17:12:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-13 17:13:42
 * @FilePath: \1000\1800\1830\1832.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> used(26);
        for (char i : sentence) {
            used[i - 'a'] = true;
        }

        for (bool i : used) {
            if (!i) {
                return false;
            }
        }

        return true;
    }
};