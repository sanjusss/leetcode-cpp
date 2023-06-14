#include "leetcode.h"

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxV = 0;
        int n = flips.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            maxV = max(maxV, flips[i]);
            if (maxV == i + 1) {
                ++ans;
            }
        }

        return ans;
    }
};