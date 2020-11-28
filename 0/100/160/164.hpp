#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         for (int i = 1; i < nums.size(); ++i) {
//             ans = max(ans, nums[i] - nums[i - 1]);
//         }

//         return ans;
//     }
// };

// //基数排序
// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) {
//             return 0;
//         }

//         int maxElement = *max_element(nums.begin(), nums.end());
//         vector<int> temps(n);
//         array<int, 10> decs;
//         for (int i = 1; i <= maxElement; i *= 10) {
//             decs.fill(0);
//             for (int j : nums) {
//                 ++decs[(j / i) % 10];
//             }

//             int sum = 0;
//             for (int j = 1; j < 10; ++j) {
//                 sum += decs[0];
//                 decs[0] = decs[j];
//                 decs[j] = sum;
//             }

//             decs[0] = 0;

//             for (int j : nums) {
//                 temps[decs[(j / i) % 10]++] = j;
//             }

//             swap(temps, nums);
//         }

//         int ans = 0;
//         for (int i = 1; i < n; ++i) {
//             ans = max(ans, nums[i] - nums[i - 1]);
//         }

//         return ans;
//     }
// };

//桶
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> buckets(bucketSize, { -1, -1 });
        for (int i : nums) {
            auto& bucket = buckets[(i - minVal) / d];
            if (bucket.first == -1) {
                bucket.first = i;
                bucket.second = i;
            }
            else {
                bucket.first = min(bucket.first, i);
                bucket.second = max(bucket.second, i);
            }
        }

        int ans = 0;
        int prev = -1;
        for (auto& bucket : buckets) {
            if (bucket.first == -1) {
                continue;
            }

            if (prev != -1) {
                ans = max(ans, bucket.first - prev);
            }

            prev = bucket.second;
        }

        return ans;
    }
};