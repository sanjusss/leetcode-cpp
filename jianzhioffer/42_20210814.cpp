/*
 * @Author: sanjusss
 * @Date: 2021-08-14 09:39:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-14 09:54:23
 * @FilePath: \jianzhioffer\42_20210814.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ans = INT_MIN;
//         int prev = 0;
//         for (int i : nums) {
//             prev = max(prev + i, i);
//             ans = max(ans, prev);
//         }

//         return ans;
//     }
// };

//分治法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        struct state {
            int lmax;
            int rmax;
            int submax;
            int sum;
        };
        function<state(int, int)> calc = [&nums, &calc](int left, int right) -> state {
            if (left == right) {
                return { nums[left], nums[left], nums[left], nums[left] };
            }

            int mid = (left + right) / 2;
            state ls = calc(left, mid);
            state rs = calc(mid + 1, right);
            return { max(ls.lmax, ls.sum + rs.lmax), max(rs.rmax, rs.sum + ls.rmax),
                     max({ ls.submax, rs.submax, ls.rmax + rs.lmax }), ls.sum + rs.sum };
        };
        return calc(0, nums.size() - 1).submax;
    }
};