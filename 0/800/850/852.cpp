/*
 * @Author: sanjusss
 * @Date: 2021-06-15 08:31:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-15 08:38:40
 * @FilePath: \0\800\850\852.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int left = 1;
//         int right = arr.size() - 2;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
//                 return mid;
//             }
//             else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
//                 right = mid - 1;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }

//         return left;
//     }
// };

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::peakIndexInMountainArray)