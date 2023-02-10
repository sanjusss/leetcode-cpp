/*
 * @Author: sanjusss
 * @Date: 2023-02-10 13:58:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-10 14:34:01
 * @FilePath: \1000\1200\1220\1223.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        static constexpr int mod = 1e9 + 7;
        vector<vector<int>> cur(6);
        for (int i = 0; i < 6; ++i) {
            cur[i].resize(rollMax[i] + 1);
            cur[i][0] = 1;
            cur[i][rollMax[i]] = 1;
        }

        auto pre = cur;
        while (--n > 0) {
            swap(cur, pre);
            for (int i = 0; i < 6; ++i) {
                int& sum = cur[i][rollMax[i]];
                sum = 0;
                for (int j = 0; j < 6; ++j) {
                    if (i != j) {
                        sum += pre[j][rollMax[j]];
                        sum %= mod;
                    }
                }

                cur[i][0] = sum;
                for (int j = rollMax[i] - 1; j > 0; --j) {
                    cur[i][j] = pre[i][j - 1];
                    sum += cur[i][j];
                    sum %= mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 6; ++i) {
            ans += cur[i][rollMax[i]];
            ans %= mod;
        }

        return ans;
    }
};