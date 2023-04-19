#include "leetcode.h"

// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n + 1);
//         vector<int> biggerI;
//         for (int i = 0; i < n; ++i) {
//             while (!biggerI.empty() && arr[biggerI.back()] <= arr[i]) {
//                 biggerI.pop_back();
//             }

//             int b = biggerI.size();
//             biggerI.push_back(i);
//             int minJ = max(0, i - k + 1);
//             for (int j = i; j >= minJ; --j) {
//                 while (b > 0 && biggerI[b - 1] >= j) {
//                     --b;
//                 }

//                 dp[i + 1] = max(dp[i + 1], dp[j] + arr[biggerI[b]] * (i - j + 1));
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < i + k && j < n; ++j) {
                cur = max(cur, arr[j]);
                dp[j + 1] = max(dp[j + 1], dp[i] + cur * (j - i + 1));
            }
        }

        return dp[n];
    }
};