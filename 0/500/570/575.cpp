/*
 * @Author: sanjusss
 * @Date: 2021-11-01 07:55:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-01 08:19:06
 * @FilePath: \0\500\570\575.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int distributeCandies(vector<int>& candyType) {
//         unordered_map<int, int> cnt;
//         for (int i : candyType) {
//             ++cnt[i];
//         }

//         vector<int> arr;
//         for (auto [_, c] : cnt) {
//             arr.push_back(c);
//         }

//         sort(arr.rbegin(), arr.rend());
//         int dis = candyType.size() / 2;
//         int types = arr.size();
//         for (int i = 0; i < types; ++i) {
//             if (arr[i] == 1) {
//                 return types - dis;
//             }

//             dis -= arr[i] - 1;
//             if (dis <= 0) {
//                 return types;
//             }
//         }

//         return 0;
//     }
// };

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};

TEST(&Solution::distributeCandies)