/*
 * @Author: sanjusss
 * @Date: 2023-05-14 10:27:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-14 10:41:35
 * @FilePath: \C\C300\C340\C345\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int dn1 = 0;
        int n = derived.size();
        for (int i = 0; i < n - 1; ++i) {
            dn1 ^= derived[i];
        }

        return dn1 == derived[n - 1];
    }
};