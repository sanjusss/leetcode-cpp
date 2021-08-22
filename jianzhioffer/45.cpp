/*
 * @Author: sanjusss
 * @Date: 2021-08-22 09:33:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 09:59:53
 * @FilePath: \jianzhioffer\45.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string minNumber(vector<int>& nums) {
        static constexpr auto move = [](int n) -> int64_t {
            if (n == 0) {
                return 10;
            }

            int64_t res = 1;
            while (n > 0) {
                n /= 10;
                res *= 10;
            }

            return res;
        };
        auto cmp = [](int a, int b) {
            return a * move(b) + b < b * move(a) + a;
        };
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (int i : nums) {
            ans += to_string(i);
        }

        return ans;
    }
};

TEST(&Solution::minNumber)