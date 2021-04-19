#include "leetcode.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for (int i : nums) {
            if (i != val) {
                nums[cur++] = i;
            }
        }

        return cur;
    }
};