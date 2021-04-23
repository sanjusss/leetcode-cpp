#include "leetcode.h"

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         int n = nums.size();
//         vector<vector<int>> dp(n);
//         for (int i = 0; i < n; ++i) {
//             int cur = -1;
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] % nums[j] == 0) {
//                     if (cur == -1 || dp[cur].size() < dp[j].size()) {
//                         cur = j;
//                     }
//                 }
//             }

//             if (cur >= 0) {
//                 dp[i] = dp[cur];
//             }

//             dp[i].push_back(nums[i]);
//             if (dp[i].size() > dp[ans].size()) {
//                 ans = i;
//             }
//         }

//         return dp[ans];
//     }
// };

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);
        int endIndex = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > dp[endIndex]) {
                endIndex = i;
            }
        }

        if (endIndex == 0) {
            return { nums[0] };
        }

        int size = dp[endIndex] - 1;
        int value = nums[endIndex];
        vector<int> ans{ value };
        for (int i = endIndex - 1; i >= 0; --i) {
            if (dp[i] == size && value % nums[i] == 0) {
                --size;
                value = nums[i];
                ans.push_back(value);
            }
        }

        return ans;
    }
};