#include "leetcode.h"

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int maxCount = 0;
        for (int i : nums) {
            maxCount = max(maxCount, ++cnt[i]);
        }

        unordered_map<int, pair<int, int>> pts;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (cnt[nums[i]] != maxCount) {
                continue;
            }

            if (pts.find(nums[i]) == pts.end()) {
                pts[nums[i]] = { i, i };
            }
            else {
                pts[nums[i]].second = i;
            }
        }

        int ans = n;
        for (auto& [_, p] : pts) {
            ans = min(ans, p.second - p.first + 1);
        }

        return ans;
    }
};

TEST(&Solution::findShortestSubArray)