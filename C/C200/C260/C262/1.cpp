/*
 * @Author: sanjusss
 * @Date: 2021-10-10 10:25:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-10 10:34:25
 * @FilePath: \C\C200\C260\C262\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());
        unordered_map<int, int> cnt;
        for (int i : s1) {
            ++cnt[i];
        }
        for (int i : s2) {
            ++cnt[i];
        }
        for (int i : s3) {
            ++cnt[i];
        }

        vector<int> ans;
        for (auto [i, c] : cnt) {
            if (c >= 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};