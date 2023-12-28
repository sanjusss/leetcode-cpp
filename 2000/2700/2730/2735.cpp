#include "leetcode.h"

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = accumulate(nums.begin(), nums.end(), 0ll);
        long long sum = ans;
        long long n = nums.size();
        vector<int> ones = nums;
        for (long long i = 1; i < n; ++i) {
            sum += x;
            for (long long j = 0; j < n; ++j) {
                long long k = (i + j) % n;
                if (ones[j] > nums[k]) {
                    sum -= ones[j] - nums[k];
                    ones[j] = nums[k];
                }
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};