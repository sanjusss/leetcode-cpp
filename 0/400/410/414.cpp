/*
 * @Author: sanjusss
 * @Date: 2021-10-06 07:30:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-06 07:48:59
 * @FilePath: \0\400\410\414.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         int cnt = 1;
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] != nums[i - 1] && ++cnt == 3) {
//                 return nums[i];
//             }
//         }

//         return nums.front();
//     }
// };

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            s.insert(i);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }

        if (s.size() == 3) {
            return *s.begin();
        }
        else {
            return *s.rbegin();
        }
    }
};

TEST(&Solution::thirdMax)