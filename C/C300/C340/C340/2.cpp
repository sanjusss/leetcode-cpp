#include "leetcode.h"

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, long long> rsum;
        unordered_map<int, int> rcnt;
        for (long long i = 0; i < n; ++i) {
            rsum[nums[i]] += i;
            ++rcnt[nums[i]];
        }

        unordered_map<int, long long> lsum;
        unordered_map<int, int> lcnt;
        vector<long long> ans(n);
        for (long long i = 0; i < n; ++i) {
            rsum[nums[i]] -= i;
            rcnt[nums[i]] -= 1;

            ans[i] = (rsum[nums[i]] - rcnt[nums[i]] * i) + (lcnt[nums[i]] * i - lsum[nums[i]]);
            lsum[nums[i]] += i;
            lcnt[nums[i]] += 1;
        }

        return ans;
    }
};