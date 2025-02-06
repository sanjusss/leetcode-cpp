/*
 * @Author: sanjusss
 * @Date: 2025-02-06 09:00:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2025-02-06 12:51:56
 * @FilePath: \0\0\40\47_20250206.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         vector<vector<int>> os;
//         do {
//             os.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end()));

//         return os;
//     }
// };

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> os;
        vector<int> cur(n);
        vector<int> put(n);
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                os.push_back(cur);
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (put[j] || (j > 0 && nums[j] == nums[j - 1] && !put[j - 1])) {
                    continue;
                }

                put[j] = 1;
                cur[i] = nums[j];
                dfs(i + 1);
                put[j] = 0;
            }
        };

        dfs(0);
        return os;
    }
};