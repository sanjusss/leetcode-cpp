#include "leetcode.h"

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int p1 = -1;
        int pn = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                p1 = i;
            }
            else if (nums[i] == n) {
                pn = i;
            }
        }

        int ans = p1 + (n - 1- pn);
        if (pn < p1) {
            ans -= 1;
        }

        return ans;
    }
};