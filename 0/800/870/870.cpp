/*
 * @Author: sanjusss
 * @Date: 2022-10-08 10:44:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-08 10:55:28
 * @FilePath: \0\800\870\870.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         vector<int> is1(n);
//         iota(is1.begin(), is1.end(), 0);
//         sort(is1.begin(), is1.end(), [&nums1] (int a, int b) {
//             return nums1[a] < nums1[b];
//         });
//         vector<int> is2(n);
//         iota(is2.begin(), is2.end(), 0);
//         sort(is2.begin(), is2.end(), [&nums2] (int a, int b) {
//             return nums2[a] < nums2[b];
//         });
//         vector<int> ansi(n, -1);
//         while (!is2.empty()) {
//             if (nums1[is1.back()] > nums2[is2.back()]) {
//                 ansi[is2.back()] = is1.back();
//                 is1.pop_back();
//             }

//             is2.pop_back();
//         }

//         vector<int> ans;
//         for (int& i : ansi) {
//             if (i == -1) {
//                 i = is1.back();
//                 is1.pop_back();
//             }

//             ans.push_back(nums1[i]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> is1(n);
        iota(is1.begin(), is1.end(), 0);
        sort(is1.begin(), is1.end(), [&nums1] (int a, int b) {
            return nums1[a] < nums1[b];
        });
        vector<int> is2(n);
        iota(is2.begin(), is2.end(), 0);
        sort(is2.begin(), is2.end(), [&nums2] (int a, int b) {
            return nums2[a] < nums2[b];
        });
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[is1[i]] > nums2[is2[left]]) {
                ans[is2[left++]] = nums1[is1[i]];
            }
            else {
                ans[is2[right--]] = nums1[is1[i]];
            }
        }

        return ans;
    }
};