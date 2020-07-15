#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int numTrees(int n) {
//        if (n <= 0) {
//            return 0;
//        }
//        else if (n == 1) {
//            return 1;
//        }
//        
//        int ans = numTrees(n - 1) * 2;
//        for (int i = 2; i < n; ++i) {
//            ans += numTrees(i - 1) * numTrees(n - i);
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int numTrees(int n) {
//        if (n <= 0) {
//            return 0;
//        }
//        else if (n == 1) {
//            return 1;
//        }
//
//        vector<int> dp(n + 1);
//        dp[1] = 1;
//        for (int i = 2; i <= n; ++i) {
//            dp[i] += dp[i - 1] * 2;
//            for (int j = 2; j < i; ++j) {
//                dp[i] += dp[j - 1] * dp[i - j];
//            }
//        }
//
//        return dp[n];
//    }
//};

//class Solution {
//public:
//    int numTrees(int n) {
//        if (n <= 0) {
//            return 0;
//        }
//        else if (n == 1) {
//            return 1;
//        }
//
//        vector<int> dp(n + 1);
//        dp[0] = 1;
//        dp[1] = 1;
//        for (int i = 2; i <= n; ++i) {
//            for (int j = 1; j <= i; ++j) {
//                dp[i] += dp[j - 1] * dp[i - j];
//            }
//        }
//
//        return dp[n];
//    }
//};

class Solution {
public:
    int numTrees(int n) {
        int arr[] = { 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190 };
        return arr[n];
    }
};