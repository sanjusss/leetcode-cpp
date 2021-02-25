#include "leetcode.h"

// class Solution {
// public:
//     int minimumIncompatibility(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> groups(k);
//         int ans = INT_MAX;
//         dfs(nums, k, nums.size() / k, groups, ans, 0);
//         return ans == INT_MAX ? -1 : ans;
//     }

// private:
//     void dfs(vector<int>& nums, int k, int maxGroup, vector<vector<int>>& groups, int& ans, int ni) {
//         if (ni == nums.size()) {
//             int sum = 0;
//             for (auto& g : groups) {
//                 sum += g.back() - g.front();
//             }

//             ans = min(ans, sum);
//             return;
//         }

//         for (int i = 0; i < k; ++i) {
//             auto& g = groups[i];
//             if (g.size() == maxGroup) {
//                 continue;
//             }

//             if (!g.empty() && g.back() == nums[ni]) {
//                 continue;
//             }

//             g.push_back(nums[ni]);
//             dfs(nums, k, maxGroup, groups, ans, ni + 1);
//             g.pop_back();
//         }
//     }
// };

// class Solution {
//     struct Calc {
//         Calc(vector<int>& nums, int k) : nums(nums), k(k), maxGroup(nums.size() / k), groups(k) {
//             dfs(0);
//         }

//         void dfs(int ni) {
//             if (ni == nums.size()) {
//                 ans = min(ans, sum);
//                 return;
//             }

//             for (int i = 0; i < k; ++i) {
//                 auto& g = groups[i];
//                 if (g.size() == maxGroup) {
//                     continue;
//                 }

//                 if (!g.empty() && g.back() == nums[ni]) {
//                     continue;
//                 }

//                 if (!g.empty()) {
//                     if (sum + nums[ni] - g.back() >= ans) {
//                         continue;
//                     }

//                     sum += nums[ni] - g.back();
//                 }

//                 g.push_back(nums[ni]);
//                 dfs(ni + 1);
//                 g.pop_back();
//                 if (!g.empty()) {
//                     sum -= nums[ni] - g.back();
//                 }
//             }
//         }

//         vector<int>& nums;
//         const int k;
//         const int maxGroup;
//         vector<vector<int>> groups;
//         int ans = INT_MAX;
//         int sum = 0;
//     };

// public:
//     int minimumIncompatibility(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         Calc calc(nums, k);
//         return calc.ans == INT_MAX ? -1 : calc.ans;
//     }
// };

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int groupSize = n / k;
        int maxMask = (1 << n) - 1;
        vector<int> value(maxMask + 1, -1);
        for (int mask = 0; mask <= maxMask; ++mask) {
            bitset<16> b(mask);
            if (b.count() != groupSize) {
                continue;
            }

            bool success = true;
            int last = -1;
            int first = -1;
            for (int i = 0; i < n; ++i) {
                if (!b[i]) {
                    continue;
                }

                if (last == nums[i]) {
                    success = false;
                    break;
                }

                last = nums[i];
                if (first == -1) {
                    first = last;
                }
            }

            if (!success) {
                continue;
            }

            value[mask] = last - first;
        }

        vector<int> dp(maxMask + 1, -1);
        dp[0] = 0;
        for (int mask = 0; mask <= maxMask; ++mask) {
            bitset<16> bMask(mask);
            if (bMask.count() % groupSize != 0) {
                continue;
            }

            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                bitset<16> bSub(sub);
                if (bSub.count() != groupSize || value[sub] == -1 || dp[mask - sub] == -1) {
                    continue;
                }

                if (dp[mask] == -1 || dp[mask - sub] + value[sub] < dp[mask]) {
                    dp[mask] = dp[mask - sub] + value[sub];
                }
            }
        }

        return dp[maxMask];
    }
};

TEST(&Solution::minimumIncompatibility)