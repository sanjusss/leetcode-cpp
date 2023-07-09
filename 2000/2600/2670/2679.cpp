#include "leetcode.h"

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }

        for (int j = 0; j < n; ++j) {
            int v = nums[0][j];
            for (int i = 1; i < m; ++i) {
                v = max(v, nums[i][j]);
            }

            ans += v;
        }

        return ans;
    }
};