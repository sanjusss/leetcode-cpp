/*
 * @Author: sanjusss
 * @Date: 2021-10-26 08:28:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-26 08:39:20
 * @FilePath: \0\400\490\496.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        unordered_map<int, int> pos;
        vector<int> nexts(n2);
        vector<int> s;
        for (int i = n2 - 1; i >= 0; --i) {
            while (!s.empty() && s.back() <= nums2[i]) {
                s.pop_back();
            }

            if (s.empty()) {
                nexts[i] = -1;
            }
            else {
                nexts[i] = s.back();
            }

            s.push_back(nums2[i]);
            pos[nums2[i]] = i;
        }

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int i : nums1) {
            ans.push_back(nexts[pos[i]]);
        }

        return ans;
    }
};