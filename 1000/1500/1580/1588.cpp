/*
 * @Author: sanjusss
 * @Date: 2021-08-29 07:51:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 08:21:21
 * @FilePath: \1000\1500\1580\1588.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int sumOddLengthSubarrays(vector<int>& arr) {
//         int ans = 0;
//         int n = arr.size();
//         for (int i = 0; i < n; ++i) {
//             int sum = arr[i];
//             ans += sum;
//             for (int j = i + 2; j < n; j += 2) {
//                 sum += arr[j - 1] + arr[j];
//                 ans += sum;
//             } 
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            cnt += ((i / 2) + 1) * ((n - i + 1) / 2);
            cnt += ((i + 1) / 2) * ((n - i) / 2);
            ans += arr[i] * cnt;
        }

        return ans;
    }
};

TEST(&Solution::sumOddLengthSubarrays)