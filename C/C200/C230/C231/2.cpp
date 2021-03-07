#include "leetcode.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t sum = 0;
        for (int i : nums) {
            sum += i;
        }

        int64_t diff = abs(sum - goal);
        int ans = diff / limit;
        if (diff % limit > 0) {
            ++ans;
        }

        return ans;
    }
};