#include "leetcode.h"

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            while (a >= 10) {
                a /= 10;
            }

            for (int j = i + 1; j < n; ++j) {
                if (gcd(a, nums[j] % 10) == 1) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};