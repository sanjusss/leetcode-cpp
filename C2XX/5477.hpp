#pragma once
#include "leetcode.h"

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j) {
                ++c;
            }

            arr[i] = c;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int target = n - i - 1;
            int j = i;
            while (j < n && arr[j] < target) {
                ++j;
            }

            if (j == n) {
                return -1;
            }

            while (j > i) {
                swap(arr[j], arr[j - 1]);
                --j;
                ++ans;
            }
        }

        return ans;
    }
};