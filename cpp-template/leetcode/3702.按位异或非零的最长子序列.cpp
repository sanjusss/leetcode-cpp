/*
 * @lc app=leetcode.cn id=3702 lang=cpp
 * @lcpr version=30404
 *
 * [3702] 按位异或非零的最长子序列
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        int zero = 0;
        int unz = 0;
        for (int i : nums) {
            if (i == 0) {
                ++zero;
            } else {
                ++unz;
            }

            x = x ^ i;
        }

        if (x == 0) {
            if (unz == 1) {
                return 1;
            } else if (unz == 0) {
                return 0;
            } else {
                return zero + unz - 1;
            }
        } else {
            return zero + unz;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n
// @lcpr case=end

 */

