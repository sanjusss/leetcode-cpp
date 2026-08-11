/*
 * @lc app=leetcode.cn id=2996 lang=cpp
 * @lcpr version=30404
 *
 * [2996] 大于等于顺序前缀和的最小缺失整数
 */

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> vs(nums.begin(), nums.end());
        while (vs.count(sum)) {
            ++sum;
        }

        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,12,14,13]\n
// @lcpr case=end

 */

