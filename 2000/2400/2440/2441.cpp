#include "leetcode.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> vs;
        int ans = -1;
        for (int i : nums) {
            if (vs.count(-i)) {
                ans = max(ans, abs(i));
            }

            vs.insert(i);
        }

        return ans;
    }
};