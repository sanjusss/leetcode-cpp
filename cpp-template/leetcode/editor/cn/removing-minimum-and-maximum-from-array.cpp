/*
 * @lc app=leetcode.cn id=2091 lang=cpp
 * @lcpr version=30404
 *
 * [2091] 从数组中移除最大值和最小值
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int minI = 0;
        int maxI = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minI]) {
                minI = i;
            }

            if (nums[i] > nums[maxI]) {
                maxI = i;
            }
        }

        int a = min(minI, maxI);
        int b = max(minI, maxI);
        return min({ b + 1, n - a, a + 1 + n - b });
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,10,7,5,4,1,8,6]\n
// @lcpr case=end

// @lcpr case=start
// [0,-4,19,1,8,-2,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [101]\n
// @lcpr case=end

 */

