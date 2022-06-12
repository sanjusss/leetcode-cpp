/*
 * @Author: sanjusss
 * @Date: 2022-06-12 10:27:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-12 16:09:57
 * @FilePath: \C\C200\C290\C297\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> suffixCnt;
        for (auto &s : ideas) {
            suffixCnt[s.substr(1)] |= 1 << (s[0] - 'a');
        }

        long long ans = 0;
        vector<vector<int>> cnt(26, vector<int>(26));
        for (auto &[_, mask] : suffixCnt) {
            for (int i = 0; i < 26; ++i) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < 26; ++j) {
                        if (!(mask & (1 << j))) {
                            ans += cnt[i][j];
                        }
                    }
                }
                else {
                    for (int j = 0; j < 26; ++j) {
                        if (mask & (1 << j)) {
                            ++cnt[i][j];
                        }
                    }
                }
            }
        }

        return ans * 2;
    }
};

TEST(&Solution::distinctNames)