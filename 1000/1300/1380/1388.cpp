#include "leetcode.h"

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        auto calc = [&] (int begin, int end) -> int {
            vector<int> cur(k + 1, INT_MIN);
            vector<int> pre1(k + 1, INT_MIN);
            vector<int> pre2(k + 1, INT_MIN);
            pre2[0] = 0;
            pre1[0] = 0;
            cur[0] = 0;
            for (auto i = begin; i != end; ++i) {
                swap(pre2, pre1);
                swap(pre1, cur);
                for (int j = 1; j <= k; ++j) {
                    cur[j] = max(pre1[j], pre2[j - 1] + slices[i]);
                }
            }

            return cur[k];
        };
        return max(calc(0, n - 1), calc(1, n));
    }
};

TEST(&Solution::maxSizeSlices)