#include "leetcode.h"

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int, int64_t> sums;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int key = nums[i] - i;
            int64_t s = nums[i];
            auto iter = sums.lower_bound(key);
            if (iter != sums.end()) {
                if (nums[i] < 0) {
                    continue;
                }

                s += iter->second;
            }

            while (iter != sums.begin() && prev(iter)->second <= s) {
                sums.erase(prev(iter));
            }

            if (sums.count(key)) {
                sums[key] = max(sums[key], s);
            }
            else {
                sums[key] = s;
            }
        }

        return sums.begin()->second;
    }
};

TEST(&Solution::maxBalancedSubsequenceSum)