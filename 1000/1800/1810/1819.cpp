/*
 * @Author: sanjusss
 * @Date: 2023-01-14 10:31:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-14 11:27:20
 * @FilePath: \1000\1800\1810\1819.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countDifferentSubsequenceGCDs(vector<int>& nums) {
//         unordered_set<int> all(nums.begin(), nums.end());
//         auto news = all;
//         while (!news.empty()) {
//             unordered_set<int> next;
//             for (int i : news) {
//                 for (int j : all) {
//                     int k = gcd(i, j);
//                     if (!all.count(k)) {
//                         next.insert(k);
//                     }
//                 }
//             }

//             for (int i : next) {
//                 all.insert(i);
//             }

//             swap(next, news);
//         }

//         return all.size();
//     }
// };

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxI = *max_element(nums.begin(), nums.end());
        vector<bool> exist(maxI + 1);
        int ans = 0;
        for (int i : nums) {
            if (!exist[i]) {
                ++ans;
                exist[i] = true;
            }
        }

        for (int i = 1; i <= maxI / 3; ++i) {
            if (exist[i]) {
                continue;
            }

            int a = 0;
            for (int j = i + i; j <= maxI && a != i; j += i) {
                if (exist[j]) {
                    a = gcd(a, j);
                }
            }

            if (i == a) {
                ++ans;
            }
        }

        return ans;
    }
};