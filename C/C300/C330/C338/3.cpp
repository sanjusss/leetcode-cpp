/*
 * @Author: sanjusss
 * @Date: 2023-03-05 10:28:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-26 11:09:07
 * @FilePath: \C\C300\C330\C338\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         vector<long long> ans;
//         for (int q : queries) {
//             long long sum = 0;
//             for (int i : nums) {
//                 sum += abs(i - q);
//             }

//             ans.push_back(sum);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int64_t n = nums.size();
        vector<long long> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<long long> ans;
        for (int q : queries) {
            int64_t lowSize = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            int64_t c = lowSize * q - sums[lowSize];
            c += sums[n] - sums[lowSize] - (n - lowSize) * q;

            ans.push_back(c);
        }

        return ans;
    }
};