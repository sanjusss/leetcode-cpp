/*
 * @Author: sanjusss
 * @Date: 2022-12-07 10:07:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-07 10:21:44
 * @FilePath: \1000\1700\1750\1755.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minOperations(vector<int>& nums1, vector<int>& nums2) {
//         if (nums1.size() > nums2.size() * 6 || nums2.size() * 1 > nums1.size() * 6) {
//             return -1;
//         }

//         int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
//         int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
//         if (sum1 == sum2) {
//             return 0;
//         }

//         if (sum1 > sum2) {
//             swap(sum1, sum2);
//             swap(nums1, nums2);
//         }

//         int target = sum2 - sum1;
//         vector<int> cnt(6);
//         for (int i : nums1) {
//             ++cnt[6 - i];
//         }

//         for (int i : nums2) {
//             ++cnt[i - 1];
//         }

//         int left = 0;
//         int right = target;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             int change = 0;
//             int c = mid;
//             for (int i = 5; i >= 1 && c > 0; --i) {
//                 change += i * min(cnt[i], c);
//                 c -= min(cnt[i], c);
//             }

//             if (change >= target) {
//                 right = mid;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }

//         return left;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size() * 6 || nums2.size() * 1 > nums1.size() * 6) {
            return -1;
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) {
            return 0;
        }

        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }

        int target = sum2 - sum1;
        vector<int> cnt(6);
        for (int i : nums1) {
            ++cnt[6 - i];
        }

        for (int i : nums2) {
            ++cnt[i - 1];
        }

        int ans = 0;
        for (int i = 5; i >= 1 && target > 0; --i) {
            int c = min((target + i - 1) / i, cnt[i]);
            ans += c;
            target -= c * i;
        }

        return ans;
    }
};