/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30403
 *
 * [1] 两数之和
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> v2i;
        const int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int v = nums[i];
            if (auto j = v2i.find(target - v); j != v2i.end()) {
                return { j->second, i };
            } else {
                v2i[v] = i;
            }
        }

        return {};
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

