/*
 * @Author: sanjusss
 * @Date: 2022-11-25 15:56:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-25 17:06:18
 * @FilePath: \0\800\800\809.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto scnt = getCnt(s);
        int n = scnt.size();
        int ans = 0;
        for (auto& w : words) {
            auto wcnt = getCnt(w);
            if (wcnt.size() != n) {
                continue;
            }

            bool success = true;
            for (int i = 0; i < n; ++i) {
                auto [i1, c1] = scnt[i];
                auto [i2, c2] = wcnt[i];
                if (i1 != i2 || c1 < c2 || (c1 > c2 && c1 < 3)) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ++ans;
            }
        }

        return ans;
    }

private:
    vector<pair<char, int>> getCnt(const string& s) {
        vector<pair<char, int>> cnt;
        for (char i : s) {
            if (cnt.empty() || cnt.back().first != i) {
                cnt.emplace_back(i, 1);
            }
            else {
                ++(cnt.back().second);
            }
        }

        return cnt;
    }
};

TEST(&Solution::expressiveWords)