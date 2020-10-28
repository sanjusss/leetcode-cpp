#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int, int> cnt;
//         for (int i : arr) {
//             ++cnt[i];
//         }

//         unordered_map<int, int> nums;
//         for (auto& i : cnt) {
//             if (nums.find(i.second) == nums.end()) {
//                 nums[i.second] = i.first;
//             }
//             else {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int i : arr) {
            ++cnt[i];
        }

        unordered_set<int> nums;
        for (auto& i : cnt) {
            if (nums.find(i.second) == nums.end()) {
                nums.insert(i.second);
            }
            else {
                return false;
            }
        }

        return true;
    }
};