/*
 * @Author: sanjusss
 * @Date: 2022-12-05 19:33:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-05 20:48:45
 * @FilePath: \1000\1600\1680\1687.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
//         int n = boxes.size();
//         vector<int> dp(n + 1);
//         int left = 0;
//         int right = 0;
//         int w = 0;
//         while (right < n) {
//             w += boxes[right][1];
//             while (right - left + 1 > maxBoxes || w > maxWeight) {
//                 w -= boxes[left++][1];
//             }

//             int t = 2;
//             dp[right + 1] = dp[right] + t;
//             for (int i = right - 1; i >= left; --i) {
//                 if (boxes[i + 1][0] != boxes[i][0]) {
//                     ++t;
//                 }

//                 dp[right + 1] = min(dp[right + 1], dp[i] + t);
//             }

//             ++right;
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> dp(n + 1);
        vector<int> change(n);
        int left = 0;
        int right = 0;
        int w = 0;
        deque<int> q;
        q.push_back(0);
        while (right < n) {
            if (right > 0) {
                change[right] = change[right - 1] + (boxes[right][0] == boxes[right - 1][0] ? 0 : 1);
            }

            w += boxes[right][1];
            while (right - left + 1 > maxBoxes || w > maxWeight) {
                if (!q.empty() && q.front() == left) {
                    q.pop_front();
                }

                w -= boxes[left++][1];
            }

            while (!q.empty() && dp[q.back()] - change[q.back()] >= dp[right] - change[right]) {
                q.pop_back();
            }

            q.push_back(right);
            dp[right + 1] = dp[q.front()] + change[right] - change[q.front()] + 2;

            ++right;
        }

        return dp[n];
    }
};

TEST(&Solution::boxDelivering)