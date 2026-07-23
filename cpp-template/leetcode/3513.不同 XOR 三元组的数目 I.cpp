/*
 * @lc app=leetcode.cn id=3513 lang=cpp
 * @lcpr version=30404
 *
 * [3513] 不同 XOR 三元组的数目 I
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        int ans = 1;
        while (ans < n) {
            ans *= 2;
        }

        if (ans == n && n > 2) {
            ans *= 2;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

 */

