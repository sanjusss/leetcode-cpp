/*
 * @Author: sanjusss
 * @Date: 2021-12-20 18:22:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-20 18:44:18
 * @FilePath: \0\400\470\475.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         sort(houses.begin(), houses.end());
//         sort(heaters.begin(), heaters.end());
//         int n = heaters.size();
//         int left = 0;
//         int right = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
//         while (left < right) {
//             bool success = true;
//             int mid = (left + right) / 2;
//             int j = 0;
//             for (int i : houses) {
//                 while (j < n) {
//                     if (i < heaters[j]) {
//                         if (i < heaters[j] - mid) {
//                             success = false;;
//                         }

//                         break;
//                     }
//                     else if (i <= heaters[j] + mid) {
//                         break;
//                     }
//                     else {
//                         ++j;
//                     }
//                 }

//                 if (j == n || !success) {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success) {
//                 right = mid;
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int ans = 0;
        int j = 0;
        for (int i : houses) {
            int dis = abs(i - heaters[j]);
            while (j < n - 1 && abs(i - heaters[j]) >= abs(i - heaters[j + 1])) {
                dis = abs(i - heaters[j + 1]);
                ++j;
            }

            ans = max(ans, dis);
        }

        return ans;
    }
};

TEST(&Solution::findRadius)