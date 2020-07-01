#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    int findLength(vector<int>& A, vector<int>& B)
//    {
//        int ans = 0;
//        int a = A.size();
//        int b = B.size();
//        vector<vector<int>> dp(a + 1, vector<int>(b + 1));
//        for (int i = 0; i < a; ++i)
//        {
//            for (int j = 0; j < b; ++j)
//            {
//                if (A[i] == B[j])
//                {
//                    dp[i + 1][j + 1] = dp[i][j] + 1;
//                    ans = max(ans, dp[i + 1][j + 1]);
//                }
//            }
//
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    int findLength(vector<int>& A, vector<int>& B)
//    {
//        int ans = 0;
//        int a = A.size();
//        int b = B.size();
//
//        for (int i = 0; i < a; ++i)
//        {
//            int length = 0;
//            for (int j = 0; j < b && i + j < a; ++j)
//            {
//                if (A[i + j] == B[j])
//                {
//                    ++length;
//                }
//                else
//                {
//                    length = 0;
//                }
//
//                ans = max(ans, length);
//            }
//        }
//
//        for (int j = 0; j < b; ++j)
//        {
//            int length = 0;
//            for (int i = 0; i < a && i + j < b; ++i)
//            {
//                if (A[i] == B[i + j])
//                {
//                    ++length;
//                }
//                else
//                {
//                    length = 0;
//                }
//
//                ans = max(ans, length);
//            }
//        }
//
//        return ans;
//    }
//};

class Solution {
public:
    const int mod = 1000000009;
    const int base = 113;

    // 使用快速幂计算 x^n % mod 的值
    long long qPow(long long x, long long n) {
        long long ret = 1;
        while (n) {
            if (n & 1) {
                ret = ret * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }

    bool check(vector<int>& A, vector<int>& B, int len) {
        long long hashA = 0;
        for (int i = 0; i < len; i++) {
            hashA = (hashA * base + A[i]) % mod;
        }
        unordered_set<long long> bucketA;
        bucketA.insert(hashA);
        long long mult = qPow(base, len - 1);
        for (int i = len; i < A.size(); i++) {
            hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
            bucketA.insert(hashA);
        }
        long long hashB = 0;
        for (int i = 0; i < len; i++) {
            hashB = (hashB * base + B[i]) % mod;
        }
        if (bucketA.count(hashB)) {
            return true;
        }
        for (int i = len; i < B.size(); i++) {
            hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
            if (bucketA.count(hashB)) {
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        int left = 1, right = min(A.size(), B.size()) + 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(A, B, mid)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left - 1;
    }
};