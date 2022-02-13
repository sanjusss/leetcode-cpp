/*
 * @Author: sanjusss
 * @Date: 2022-02-13 10:12:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 12:11:28
 * @FilePath: \0\200\250\259.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        vector<int> cnt(201);
        for (int i : nums) {
            ++cnt[i + 100];
        }

        int ans = 0;
        vector<int> sums(201);
        for (int i = 0; i <= 200; ++i) {
            for (int j = i; j <= 200; ++j) {
                int k = target - (i - 100) - (j - 100) + 100;
                if (k >= 0 && k <= 200) {
                    if (i == j) {
                        ans += cnt[i] * (cnt[i] - 1) / 2 * sums[k];
                        if (i < k) {
                            ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                        }
                    }
                    else {
                        ans += cnt[i] * cnt[j] * sums[k];
                        if (i < k) {
                            ans += cnt[j] * cnt[i] * (cnt[i] - 1) / 2;
                        }
                        // else if (j == k) {
                        //     ans += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                        // }
                    }
                }
            }

            for (int j = i + 1; j <= 200; ++j) {
                sums[j] += cnt[i];
            }
        }

        return ans;
    }
};

TEST(&Solution::threeSumSmaller)