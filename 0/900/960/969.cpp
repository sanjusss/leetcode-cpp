/*
 * @Author: sanjusss
 * @Date: 2022-02-19 16:32:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-19 17:11:38
 * @FilePath: \0\900\960\969.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> pancakeSort(vector<int>& arr) {
//         vector<int> ans;
//         auto swap2 = [&] (int i) {
//             swap(arr[i], arr[i + 1]);
//             if (i == 0) {
//                 ans.push_back(2);
//             }
//             else {
//                 ans.push_back(i + 2);
//                 ans.push_back(2);
//                 ans.push_back(i + 2);
//             }
//         };

//         int n = arr.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = n - 1; j > i; --j) {
//                 if (arr[j] < arr[j - 1]) {
//                     swap2(j - 1);
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        auto swap2 = [&] (int i, int target) {
            if (i == target) {
                return;
            }

            reverse(arr.begin(), arr.begin() + (i + 1));
            reverse(arr.begin(), arr.begin() + (target + 1));
            ans.push_back(i + 1);
            ans.push_back(target + 1);
        };

        int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            int maxj = i;
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[maxj]) {
                    maxj = j;
                }
            }

            swap2(maxj, i);
        }

        return ans;
    }
};