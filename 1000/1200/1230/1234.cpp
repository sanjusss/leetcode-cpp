/*
 * @Author: sanjusss
 * @Date: 2023-02-13 09:22:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-13 09:49:34
 * @FilePath: \1000\1200\1230\1234.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> c2i = {
            { 'Q', 0 },
            { 'W', 1 },
            { 'E', 2 },
            { 'R', 3 },
        };
        int n = s.size();
        int t = n / 4;
        vector<vector<int>> cnt(1, vector<int>(4));
        for (char c : s) {
            cnt.push_back(cnt.back());
            cnt.back()[c2i[c]] += 1;
        }

        int ans = n - 1;
        int left = 0;   // 开始移除
        int right = n;  // 结束移除，长度为right - left
        while (left < n) {
            bool valid = true;
            for (int i : cnt[left]) {
                if (i > t) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                break;
            }

            while (right - 1 >= left) {
                valid = true;
                for (int i = 0; i < 4; ++i) {
                    if (cnt[left][i] + (cnt.back()[i] - cnt[right - 1][i]) > t) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    --right;
                }
                else {
                    break;
                }
            }

            valid = true;
            for (int i = 0; i < 4; ++i) {
                if (cnt[left][i] + (cnt.back()[i] - cnt[right][i]) > t) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans = min(ans, right - left);
            }
            
            ++left;
            right = min(right + 1, n);
        }

        return ans;
    }
};

TEST(&Solution::balancedString)