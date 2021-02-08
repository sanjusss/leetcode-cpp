#include "leetcode.h"

// class Solution {
// public:
//     int maxTurbulenceSize(vector<int>& arr) {
//         int ans = 0;
//         int left = 0;
//         int right = 0;
//         int n = arr.size();
//         int sign = 0;
//         while (right < n) {
//             if (right > 0) {
//                 int cur = 0;
//                 if (arr[right] > arr[right - 1]) {
//                     cur = 1;
//                 }
//                 else if (arr[right] < arr[right - 1]) {
//                     cur = -1;
//                 }

//                 if (cur == 0) {
//                     left = right;
//                 }
//                 else if (cur == sign){
//                     left = right - 1;
//                 }

//                 sign = cur;
//             }

//             ++right;
//             ans = max(ans, right - left);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int left = 0;
        int right = 0;
        int n = arr.size();
        while (right < n - 1) {
            if (left == right) {
                if (arr[right] == arr[right + 1]) {
                    ++left;
                }

                ++right;
            }
            else {
                if (arr[right] > arr[right - 1] && arr[right] > arr[right + 1]) {
                    ++right;
                }
                else if (arr[right] < arr[right - 1] && arr[right] < arr[right + 1]) {
                    ++right;
                }
                else {
                    left = right;
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

TEST(&Solution::maxTurbulenceSize)