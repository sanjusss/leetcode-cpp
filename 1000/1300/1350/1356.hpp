#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         unordered_map<int, int> bits;
//         for (int i : arr) {
//             if (bits.find(i) != bits.end()) {
//                 continue;
//             }

//             int cnt = 0;
//             for (int j = 0; j <= 14; ++j) {
//                 if (i & (1 << j)) {
//                     ++cnt;
//                 }
//             }

//             bits[i] = cnt;
//         }

//         sort(arr.begin(), arr.end(), [&bits](int a, int b) {
//             if (bits[a] == bits[b]) {
//                 return a < b;
//             }
//             else {
//                 return bits[a] < bits[b];
//             }
//         });
//         return arr;
//     }
// };

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits(10001);
        for (int i = 1; i <= 10000; ++i) {
            bits[i] = bits[i >> 1] + (i & 1);
        }

        sort(arr.begin(), arr.end(), [&bits](int a, int b) {
            if (bits[a] == bits[b]) {
                return a < b;
            }
            else {
                return bits[a] < bits[b];
            }
        });
        return arr;
    }
};