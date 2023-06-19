#include "leetcode.h"

// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;
//         int one1 = INT_MAX / 4;
//         int one2 = INT_MAX / 4;
//         int two1 = INT_MAX / 4;
//         int two2 = INT_MAX / 4;
//         for (int i : nums) {
//             sum += i;
//             if (i % 3 == 1) {
//                 if (i < one1) {
//                     one2 = one1;
//                     one1 = i;
//                 }
//                 else if (i < one2) {
//                     one2 = i;
//                 }
//             }
//             else if (i % 3 == 2) {
//                 if (i < two1) {
//                     two2 = two1;
//                     two1 = i;
//                 }
//                 else if (i < two2) {
//                     two2 = i;
//                 }
//             }
//         }

//         if (sum % 3 == 1) {
//             sum -= min(one1, two1 + two2);
//         }
//         else if (sum % 3 == 2) {
//             sum -= min(two1, one1 + one2);
//         }

//         return max(0, sum);
//     }
// };

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> cur = {0, INT_MIN, INT_MIN };
        vector<int> pre(3);
        for (int i : nums) {
            swap(cur, pre);
            for (int j = 0; j < 3; ++j) {
                cur[j] = pre[j];
            }

            for (int j = 0; j < 3; ++j) {
                int v = pre[j] + i;
                cur[(j + i) % 3] = max(cur[(j + i) % 3], v); 
            }
        }

        return cur[0];
    }
};