/*
 * @Author: sanjusss
 * @Date: 2021-07-09 08:18:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-09 08:28:40
 * @FilePath: \chengxuyuanmianshijindian\1710.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int half = nums.size() / 2 + 1;
//         unordered_map<int, int> cnt;
//         for (int i : nums) {
//             if (++cnt[i] == half) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = -1;
        int cnt = 0;
        for (int i : nums) {
            if (cnt == 0) {
                target = i;
                cnt = 1;
            }
            else if (target == i) {
                ++cnt;
            }
            else {
                --cnt;
            }
        }

        int half = nums.size() / 2 + 1;
        cnt = 0;
        for (int i : nums) {
            if (target == i && ++cnt == half) {
                return target;
            }
        }

        return -1;
    }
};

TEST(&Solution::majorityElement)