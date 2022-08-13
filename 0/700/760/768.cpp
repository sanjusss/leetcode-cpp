/*
 * @Author: sanjusss
 * @Date: 2022-08-13 10:01:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-13 10:22:02
 * @FilePath: \0\700\760\768.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> is(n);
//         iota(is.begin(), is.end(), 0);
//         sort(is.begin(), is.end(), [&arr](int a, int b) {
//             if (arr[a] == arr[b]) {
//                 return a < b;
//             }
//             else {
//                 return arr[a] < arr[b];
//             }
//         });
//         int ans = 0;
//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         int left = 0;
//         for (int j = 0; j < n; ++j) {
//             int i = is[j];
//             mini = min(i, mini);
//             maxi = max(i, maxi);
//             if (mini == left && maxi == j) {
//                 ++ans;
//                 left = j + 1;
//                 mini = INT_MAX;
//                 maxi = INT_MIN;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for (int i : arr) {
            if (s.empty() || i >= s.top()) {
                s.push(i);
            }
            else {
                int top = s.top();
                s.pop();
                while (!s.empty() && i < s.top()) {
                    s.pop();
                }

                s.push(top);
            }
        }

        return s.size();
    }
};