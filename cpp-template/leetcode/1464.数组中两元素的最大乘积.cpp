/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 * @lcpr version=30404
 *
 * [1464] 数组中两元素的最大乘积
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        for (int i : nums) {
            if (i > max1) {
                max2 = max1;
                max1 = i;
            } else if (i > max2) {
                max2 = i;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,7]\n
// @lcpr case=end

 */

