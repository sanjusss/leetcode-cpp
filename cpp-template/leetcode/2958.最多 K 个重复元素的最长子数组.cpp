/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 * @lcpr version=30404
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        const int n = nums.size();
        int b = 0;
        for (int e = 0; e < n; ++e) {
            if (++cnt[nums[e]] > k) {
                do {
                    --cnt[nums[b++]];
                } while (cnt[nums[e]] > k);
            }

            ans = max(ans, e + 1 - b);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1,2,3,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5,5,5,5]\n4\n
// @lcpr case=end

 */

