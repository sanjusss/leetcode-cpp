/*
 * @lc app=leetcode.cn id=3471 lang=cpp
 * @lcpr version=30404
 *
 * [3471] 找出最大的几近缺失整数
 */

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = k - 1; i < n; ++i) {
            unordered_set<int> vs;
            for (int j = i - k + 1; j <= i; ++j) {
                vs.insert(nums[j]);
            }

            for (auto j : vs) {
                cnt[j] += 1;
            }
        }

        
        int ans = -1;
        for (auto [i, c] : cnt) {
            if (c == 1) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,2,1,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,9,7,2,1,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [0,0]\n1\n
// @lcpr case=end

 */

