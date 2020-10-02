#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool divisorGame(int N) {
//        if (N <= 1) {
//            return false;
//        }
//
//        if (m_results.find(N) == m_results.end()) {
//            bool res = false;
//            for (int i = 1; i < N && res == false; ++i) {
//                if (N % i == 0) {
//                    res = !(divisorGame(N - i));
//                }
//            }
//
//            m_results[N] = res;
//        }
//
//        return m_results[N];
//    }
//
//private:
//    unordered_map<int, bool> m_results;
//};

//class Solution {
//public:
//    bool divisorGame(int N) {
//        vector<bool> dp(N + 1);
//        for (int i = 1; i <= N; ++i) {
//            for (int j = 1; j <= i && i + j <= N; ++j) {
//                if (i % j == 0) {
//                    dp[i + j] = dp[i + j] || (!dp[i]);
//                }
//            }
//        }
//
//        return dp[N];
//    }
//};

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};