/*
 * @Author: sanjusss
 * @Date: 2021-12-27 08:46:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-27 09:30:43
 * @FilePath: \0\800\820\825.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         int n = ages.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i != j && ages[j] > 0.5 * ages[i] + 7 && ages[j] <= ages[i] && !(ages[j] > 100 && ages[i] < 100))
//                 {
//                     ++ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         map<int, int> cnt;
//         for (int i : ages) {
//             ++cnt[i];
//         }

//         int ans = 0;
//         auto fast = cnt.begin();
//         auto slow = cnt.begin();
//         int sum = 0;
//         while (fast != cnt.end()) {
//             int c = fast->second;
//             double minAge = fast->first * 0.5 + 7;
//             if (fast->first > minAge) {
//                 ans += c * (c - 1);
//             }

//             while (slow != fast && slow->first <= minAge) {
//                 sum -= slow->second;
//                 ++slow;
//             }

//             ans += sum * c;
//             sum += c;
//             ++fast;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int ans = 0;
        int n = ages.size();
        int left = 0;
        int right = 0;
        for (int i : ages) {
            double minAge = i * 0.5 + 7;
            while (left < n && ages[left] <= minAge) {
                ++left;
            }

            while (right + 1 < n && ages[right + 1] <= i) {
                ++right;
            }

            ans += max(right - left, 0);
        }

        return ans;
    }
};

TEST(&Solution::numFriendRequests)