#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i1 = 0;
        int i2 = 0;
        while (i1 < n1 || i2 < n2) {
            if (i2 == n2 || (i1 < n1 && nums1[i1][0] <= nums2[i2][0])) {
                ans.push_back(move(nums1[i1++]));
            }
            else {
                if (!ans.empty() && ans.back()[0] == nums2[i2][0]) {
                    ans.back()[1] += nums2[i2][1];
                }
                else {
                    ans.push_back(move(nums2[i2]));
                }

                ++i2;
            }
        }

        return ans;
    }
};