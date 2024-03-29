#include "leetcode.h"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        deque<int> rights;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            while (!rights.empty() && rights.back() > nums[i]) {
                rights.pop_back();
            }

            rights.push_back(nums[i]);
        }

        int ans = INT_MAX;
        int left = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            if (!rights.empty() && rights.front() == nums[i]) {
                rights.pop_front();
            }

            if (left < nums[i] && !rights.empty() && nums[i] > rights.front()) {
                ans = min(ans, left + nums[i] + rights.front());
            }

            left = min(left, nums[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

TEST(&Solution::minimumSum)