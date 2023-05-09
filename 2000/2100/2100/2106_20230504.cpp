/*
 * @Author: sanjusss
 * @Date: 2023-05-04 08:57:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-04 09:47:58
 * @FilePath: \2000\2100\2100\2106_20230504.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//         int ans = 0;

//         int n = fruits.size();
//         vector<int> sums(n + 1);
//         queue<int> q;
//         int startI = -1;
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + fruits[i][1];
//             if (fruits[i][0] < startPos) {
//                 q.push(i);
//                 continue;
//             }
//             else if (fruits[i][0] - startPos > k) {
//                 continue;
//             }

//             if (startI == -1) {
//                 startI = i;
//             }

//             while (!q.empty() && (fruits[i][0] - fruits[q.front()][0]) + (fruits[i][0] - startPos) > k) {
//                 q.pop();
//             }

//             int preI = startI;
//             if (!q.empty()) {
//                 preI = q.front();
//             }

//             ans = max(ans, sums[i + 1] - sums[preI]);
//         }

//         q = {};
//         int endI = -1;
//         for (int i = n - 1; i >= 0; --i) {
//             if (fruits[i][0] > startPos) {
//                 q.push(i);
//                 continue;
//             }
//             else if (startPos - fruits[i][0] > k) {
//                 break;
//             }

//             if (endI == -1) {
//                 endI = i;
//             }

//             while (!q.empty() && (fruits[q.front()][0] - fruits[i][0]) + (startPos - fruits[i][0]) > k) {
//                 q.pop();
//             }

//             int lastI = endI;
//             if (!q.empty()) {
//                 lastI = q.front();
//             }

//             ans = max(ans, sums[lastI + 1] - sums[i]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int n = fruits.size();
        for (int left = 0, right = 0, sum = 0; right < n && fruits[right][0] <= startPos + k; ++right) {
            sum += fruits[right][1];
            if (fruits[right][0] < startPos) {
                continue;
            }

            while (fruits[left][0] < startPos && (fruits[right][0] - startPos) + (fruits[right][0] - fruits[left][0]) > k) {
                sum -= fruits[left++][1];
            }

            ans = max(ans, sum);
        }

        for (int left = n - 1, right = n - 1, sum = 0; left >= 0 && fruits[left][0] >= startPos - k; --left) {
            sum += fruits[left][1];
            if (fruits[left][0] > startPos) {
                continue;
            }

            while (fruits[right][0] > startPos && (fruits[right][0] - fruits[left][0]) + (startPos - fruits[left][0]) > k) {
                sum -= fruits[right--][1];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};