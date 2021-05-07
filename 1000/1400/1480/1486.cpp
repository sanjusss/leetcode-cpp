#include "leetcode.h"

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = ans ^ (start + i * 2);
        }

        return ans;
    }
};

TEST(&Solution::xorOperation)