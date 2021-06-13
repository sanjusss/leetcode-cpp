/*
 * @Author: sanjusss
 * @Date: 2021-06-13 10:25:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-13 10:48:08
 * @FilePath: \C\C200\C240\C245\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0;
        int right = removable.size();
        int sn = s.size();
        int pn = p.size();
        vector<bool> removed(s.size());
        while (left < right) {
            int mid = (left + right + 1) / 2;
            fill(removed.begin(), removed.end(), false);
            for (int i = 0; i < mid; ++i) {
                removed[removable[i]] = true;
            }

            int pi = 0;
            for (int si = 0; si < sn && pi < pn; ++si) {
                if (removed[si]) {
                    continue;
                }

                if (s[si] == p[pi]) {
                    ++pi;
                }
            }

            if (pi == pn) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

TEST(&Solution::maximumRemovals)