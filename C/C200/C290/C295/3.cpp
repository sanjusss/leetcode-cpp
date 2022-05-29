/*
 * @Author: sanjusss
 * @Date: 2022-05-29 10:27:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-29 11:38:39
 * @FilePath: \C\C200\C290\C295\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int totalSteps(vector<int>& nums) {
//         int ans = 0;
//         vector<int> is(nums.size());
//         iota(is.begin(), is.end(), 0);
//         while (true) {
//             vector<int> nx;
//             nx.push_back(is[0]);
//             for (int j = 1; j < is.size(); ++j) {
//                 if (nums[is[j - 1]] > nums[is[j]]) {
//                     continue;
//                 }

//                 nx.push_back(is[j]);
//             }

//             if (nx.size() == is.size()) {
//                 break;
//             }
//             else {
//                 ++ans;
//                 is = move(nx);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        vector<pair<int, int>> s;
        while (i < n) {
            int j = i + 1;
            int cnt = 0;
            while (j < n && nums[i] > nums[j]) {
                if (s.empty() || s.back().first > nums[j]) {
                    s.emplace_back(nums[j], 1);
                }
                else {
                    s.back().first = nums[j];
                    s.back().second += 1;
                    while (s.size() > 1 && s[s.size() - 2].first <= nums[j]) {
                        s[s.size() - 2].first = nums[j];
                        s[s.size() - 2].second = max(s.back().second, s[s.size() - 2].second + 1);
                        s.pop_back();
                    }
                }

                cnt = max(cnt, s.back().second);
                ++j;
            }

            s.clear();
            ans = max(ans, cnt);
            i = j;
        }

        return ans;
    }
};

TEST(&Solution::totalSteps)