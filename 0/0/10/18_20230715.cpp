#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }

            for (int b = a + 1; b < n; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }

                int64_t sum = (int64_t)target - nums[a] - nums[b];
                int left = b + 1;
                int right = n - 1;
                while (left < right) {
                    int64_t cur = nums[left] + nums[right];
                    if (cur <= sum) {
                        if (cur == sum) {
                            ans.push_back({ nums[a], nums[b], nums[left], nums[right] });
                        }

                        do {
                            ++left;
                        } while (left < right && nums[left - 1] == nums[left]);
                    }
                    else {
                        do {
                            --right;
                        } while (left < right && nums[right + 1] == nums[right]);
                    }
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::fourSum)