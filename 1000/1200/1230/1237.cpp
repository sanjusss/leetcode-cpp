#include "leetcode.h"

class CustomFunction {
public:
    int f(int, int);
};

// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int>> ans;
//         int maxRight = 1000;
//         for (int i = 1; i <= 1000 && maxRight > 0; ++i) {
//             int left = 1;
//             int right = maxRight;
//             while (left <= right) {
//                 int mid = (left + right) / 2;
//                 int res = customfunction.f(i, mid);
//                 if (res >= z) {
//                     maxRight = min(maxRight, mid - 1);
//                 }

//                 if (res == z) {
//                     ans.push_back({{ i, mid }});
//                     break;
//                 }
//                 else if (res > z) {
//                     right = mid - 1;
//                 }
//                 else {
//                     left = mid + 1;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int i = 1;
        int j = z;
        while (i > 0 && i <= 1000 && j > 0 && j <= 1000) {
            int res = customfunction.f(i, j);
            if (res == z) {
                ans.push_back({{ i, j }});
                ++i;
                --j;
            }
            else if (res > z) {
                --j;
            }
            else {
                ++i;
            }
        }

        return ans;
    }
};