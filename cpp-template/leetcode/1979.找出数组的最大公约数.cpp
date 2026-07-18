/*
 * @lc app=leetcode.cn id=1979 lang=cpp
 * @lcpr version=30404
 *
 * [1979] 找出数组的最大公约数
 */

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minv = *min_element(nums.begin(), nums.end());
        int maxv = *max_element(nums.begin(), nums.end());
        return gcd(minv, maxv);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,6,9,10]\n
// @lcpr case=end

// @lcpr case=start
// [7,5,6,8,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n
// @lcpr case=end

 */

