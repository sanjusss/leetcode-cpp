/*
 * @Author: sanjusss
 * @Date: 2021-10-02 13:17:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-02 13:46:02
 * @FilePath: \0\0\10\15_20211002.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         unordered_map<int, int> cnt;
//         for (int i : nums) {
//             ++cnt[i];
//         }

//         vector<vector<int>> ans;
//         for (auto i = cnt.begin(); i != cnt.end(); ++i) {
//             --i->second;
//             for (auto j = i; j != cnt.end(); ++j) {
//                 if (j->second == 0) {
//                     continue;
//                 }

//                 int k = 0 - i->first - j->first;
//                 if (k < i->first || k < j->first) {
//                     continue;
//                 }

//                 --j->second;
//                 if (cnt.count(k) && cnt[k] > 0) {
//                     ans.push_back({ i->first, j->first, k });
//                 }

//                 ++j->second;
//             }

//             ++i->second;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         for (auto i = nums.begin(); i != nums.end() && *i <= 0; i = upper_bound(nums.begin(), nums.end(), *i)) {
//             for (auto j = next(i); j != nums.end() && *i + *j <= 0; j = upper_bound(nums.begin(), nums.end(), *j)) {
//                 int target = 0 - *i - *j;
//                 if (binary_search(next(j), nums.end(), target)) {
//                     ans.push_back({ *i, *j, target });
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (left - 1 > i && nums[left] == nums[left - 1]) {
                    ++left;
                    continue;
                }

                if (right + 1 < n && nums[right] == nums[right + 1]) {
                    --right;
                    continue;
                }

                if (nums[left] + nums[right] == -nums[i]) {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    ++left;
                }
                else if (nums[left] + nums[right] > -nums[i]) {
                    --right;
                }
                else {
                    ++left;
                }
            }
        }

        return ans;
    }
};