/*
 * @Author: sanjusss
 * @Date: 2021-10-10 10:25:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-10 11:03:49
 * @FilePath: \C\C200\C260\C262\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            for (int i : row) {
                nums.push_back(i);
            }
        }

        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if ((nums[i] - nums[i - 1]) % x != 0) {
                return -1;
            }
        }

        sort(nums.begin(), nums.end());
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        int ans = INT_MAX;
        for (int t = 1e4; t > 0; --t) {
            if ((nums[0] - t) % x != 0) {
                continue;
            }

            int p = upper_bound(nums.begin(), nums.end(), t) - nums.begin();
            int rightSub = sums[n] - sums[p] - (n - p) * t;
            int leftAdd = p * t - sums[p];
            if (leftAdd % x != 0 || rightSub % x != 0) {
                continue;
            }

            int changes = (leftAdd + rightSub) / x;
            ans = min(ans, changes);
        }

        return ans;
    }
};

TEST(&Solution::minOperations)