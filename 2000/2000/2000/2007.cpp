/*
 * @Author: sanjusss
 * @Date: 2024-04-18 08:52:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-18 08:56:12
 * @FilePath: \2000\2000\2000\2007.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> cnt;
        for (int i : changed) {
            ++cnt[i];
        }

        vector<int> arr;
        for (auto& [i, c] : cnt) {
            if (i == 0) {
                if (c % 2 != 0) {
                    return {};
                }

                for (int j = c / 2; j > 0; --j) {
                    arr.push_back(i);
                }
            }
            else if (c != 0) {
                if (!cnt.count(i * 2) || cnt[i * 2] < c) {
                    return {};
                }

                cnt[i * 2] -= c;
                for (int j = c; j > 0; --j) {
                    arr.push_back(i);
                }
            }

            c = 0;
        }

        return arr;
    }
};