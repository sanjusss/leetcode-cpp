/*
 * @Author: sanjusss
 * @Date: 2021-04-17 08:43:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-17 09:37:59
 * @FilePath: \0\200\220\220.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         set<int> s;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (i > k) {
//                 s.erase(nums[i - k - 1]);
//             }

//             auto p = s.lower_bound(max(nums[i], INT_MIN + t) - t);
//             if (p != s.end() && *p <= min(INT_MAX - t, nums[i]) + t) {
//                 return true;
//             }

//             s.insert(nums[i]);
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int64_t, int64_t> hash;
        auto key = [t](int v) -> int64_t {
            if (v < 0) {
                return (v + 1ll) / (t + 1ll) - 1; 
            }
            else {
                return v / (t + 1ll);
            }
        };
        for (int i = 0; i < nums.size(); ++i) {
            int id = key(nums[i]);
            auto p = hash.find(id);
            if (p != hash.end()) {
                return true;
            }

            p = hash.find(id - 1);
            if (p != hash.end() && nums[i] - p->second <= t) {
                return true;
            }

            p = hash.find(id + 1);
            if (p != hash.end() && p->second - nums[i] <= t) {
                return true;
            }

            hash.emplace(id, nums[i]);
            if (i >= k) {
                hash.erase(key(nums[i - k]));
            }
        }

        return false;
    }
};

TEST(&Solution::containsNearbyAlmostDuplicate)