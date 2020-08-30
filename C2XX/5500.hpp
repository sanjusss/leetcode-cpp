#pragma once
#include "leetcode.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int fisrtNg = -1;
        int ng = 0;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                fisrtNg = -1;
                ng = 0;
                start = -1;
                continue;
            }
            
            if (start == -1) {
                start = i;
            }

            if (nums[i] < 0) {
                ++ng;
                if (fisrtNg == -1) {
                    fisrtNg = i;
                }
            }

            if (ng % 2 == 0) {
                ans = max(ans, i - start + 1);
            }
            else {
                ans = max(ans, i - fisrtNg);
            }
        }

        return ans;
    }
};