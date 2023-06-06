/*
 * @Author: sanjusss
 * @Date: 2023-06-06 16:53:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-07 05:40:25
 * @FilePath: \0\400\410\411.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int m = target.size();
        int endMask = 1 << m;
        vector<bool> similars(endMask);
        for (auto& w : dictionary) {
            if (w.size() != m) {
                continue;
            }

            int mask = 0;
            for (int i = 0; i < m; ++i) {
                if (w[i] == target[i]) {
                    mask |= 1 << i;
                }
            }

            if (similars[mask]) {
                continue;
            }

            for (int sub = mask; sub > 0; sub = mask & (sub - 1)) {
                similars[sub] = true;
            }

            similars[0] = true;
        }

        int ansMask = endMask - 1;
        int ansSize = m;
        for (int mask = 0; mask < endMask; ++mask) {
            if (similars[mask]) {
                continue;
            }

            int len = 0;
            int size = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    if (len > 0) {
                        if (len >= 10) {
                            size += 2;
                        }
                        else {
                            ++size;
                        }

                        len = 0;
                    }

                    ++size;
                }
                else {
                    ++len;
                }
            }

            if (len > 0) {
                if (len >= 10) {
                    size += 2;
                }
                else {
                    ++size;
                }

                len = 0;
            }

            if (size >= ansSize) {
                continue;
            }

            ansSize = size;
            ansMask = mask;
        }

        string ans;
        int len = 0;
        for (int i = 0; i < m; ++i) {
            if (ansMask & (1 << i)) {
                if (len > 0) {
                    ans += to_string(len);
                    len = 0;
                }

                ans.push_back(target[i]);
            }
            else {
                ++len;
            }
        }

        if (len > 0) {
            ans += to_string(len);
        }

        return ans;
    }
};