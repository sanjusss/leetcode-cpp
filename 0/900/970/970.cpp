/*
 * @Author: sanjusss
 * @Date: 2023-05-02 07:50:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-02 07:54:01
 * @FilePath: \0\900\970\970.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; j + i <= bound; j *= y) {
                ans.insert(j + i);
                if (y == 1) {
                    break;
                }
            }

            if (x == 1) {
                break;
            }
        }

        return { ans.begin(), ans.end() };
    }
};