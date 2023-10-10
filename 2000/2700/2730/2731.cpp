#include "leetcode.h"

class Solution {
public:
    int sumDistance(vector<int> &nums, string s, int d) {
        static constexpr int64_t mod = 1e9 + 7;
        int n = nums.size();
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back(nums[i] + (s[i] == 'L' ? -1 : 1) * d);
        }

        sort(arr.begin(), arr.end());
        int64_t ans = 0;
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            int64_t p = (arr[i] + mod * mod) % mod;
            ans += p * i + mod - sum;
            ans %= mod;
            sum += p;
            sum %= mod;
        }

        return ans;
    }
};

TEST(&Solution::sumDistance)