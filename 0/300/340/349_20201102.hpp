#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> nums1set(nums1.begin(), nums1.end());
//         vector<int> ans;
//         for (int i : nums2) {
//             if (nums1set.find(i) != nums1set.end()) {
//                 nums1set.erase(i);
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

                ++i;
                ++j;
            }
            else if (nums1[i] > nums2[j]) {
                ++j;
            }
            else {
                ++i;
            }
        }

        return ans;
    }
};