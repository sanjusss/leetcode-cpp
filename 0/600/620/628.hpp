#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         vector<int> maxs(4, INT_MIN);
//         vector<int> mins(4, INT_MAX);
//         maxs[0] = 1;
//         mins[0] = 1;
//         for (int i : nums) {
//             for (int j = 3; j > 0; --j) {
//                 if (maxs[j - 1] == INT_MIN || mins[j - 1] == INT_MAX) {
//                     continue;
//                 }

//                 maxs[j] = max({ maxs[j], maxs[j - 1] * i, mins[j - 1] * i });
//                 mins[j] = min({ mins[j], maxs[j - 1] * i, mins[j - 1] * i });
//             }
//         }

//         return maxs[3];
//     }
// };

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i : nums) {
            if (i > max1) {
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if (i > max2) {
                max3 = max2;
                max2 = i;
            }
            else if (i > max3) {
                max3 = i;
            }

            if (i < min1) {
                min2 = min1;
                min1 = i;
            }
            else if (i < min2) {
                min2 = i;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};