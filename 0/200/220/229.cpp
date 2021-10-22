/*
 * @Author: sanjusss
 * @Date: 2021-10-22 10:24:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-22 10:37:43
 * @FilePath: \0\200\220\229.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> cnt;
//         for (int i : nums) {
//             ++cnt[i];
//         }

//         int target = nums.size() / 3;
//         vector<int> ans;
//         for (auto [i, c] : cnt) {
//             if (c > target) {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0;
        int n2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i : nums) {
            if (cnt1 > 0 && n1 == i) {
                ++cnt1;
            }
            else if (cnt2 > 0 && n2 == i) {
                ++cnt2;
            }
            else if (cnt1 == 0) {
                n1 = i;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                n2 = i;
                cnt2 = 1;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }

        int t1 = 0;
        int t2 = 0;
        for (int i : nums) {
            if (cnt1 > 0 && i == n1) {
                ++t1;
            }
            
            if (cnt2 > 0 && i == n2) {
                ++t2;
            }
        }

        int target = nums.size() / 3;
        vector<int> ans;
        if (t1 > target) {
            ans.push_back(n1);
        }

        if (t2 > target) {
            ans.push_back(n2);
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::majorityElement)