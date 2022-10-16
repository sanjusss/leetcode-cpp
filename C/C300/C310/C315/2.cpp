/*
 * @Author: sanjusss
 * @Date: 2022-10-16 10:35:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-16 10:42:07
 * @FilePath: \C\C300\C310\C315\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> all;
        for (int i : nums) {
            all.insert(i);
            int v = 0;
            while (i > 0) {
                v = v * 10 + i % 10;
                i /= 10;
            }

            all.insert(v);
        }

        return all.size();
    }
};