#include "leetcode.h"

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 1;
        int pre1 = 1;
        int pre2 = 1;
        for (int i = 1; i < n; ++i) {
            int cur1 = 1;
            if (nums1[i] >= nums1[i - 1]) {
                cur1 = max(cur1, pre1 + 1);
            }

            if (nums1[i] >= nums2[i - 1]) {
                cur1 = max(cur1, pre2 + 1);
            }

            int cur2 = 1;
            if (nums2[i] >= nums1[i - 1]) {
                cur2 = max(cur2, pre1 + 1);
            }

            if (nums2[i] >= nums2[i - 1]) {
                cur2 = max(cur2, pre2 + 1);
            }

            ans = max(ans, cur1);
            ans = max(ans, cur2);
            pre1 = cur1;
            pre2 = cur2;
        }

        return ans;
    }
};