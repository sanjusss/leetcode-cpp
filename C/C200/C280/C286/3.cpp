/*
 * @Author: sanjusss
 * @Date: 2022-03-27 10:27:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-27 11:34:39
 * @FilePath: \C\C200\C280\C286\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        int maxK = count(pow10(intLength) - 1, intLength);
        for (int i : queries) {
            if (i > maxK) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(kth(i, intLength));
            }
        }

        return ans;
    }

private:
    static long long kth(int k, int intLength) {
        long long left = pow10(intLength - 1);
        long long right = left * 10 - 1;

        while (left < right) {
            long long mid = (right + left) / 2;
            if (count(mid, intLength) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

    static int count(long long n, int intLength) {
        if (intLength == 1) {
            return n;
        }
        else if (intLength % 2 == 0) { // 偶数长度
            long long base = pow10(intLength / 2);
            long long high = n / base;
            long long low = n % base;
            int ans = high - base / 10 + 1;
            if (low < reverse(high)) {
                --ans;
            }

            return ans;
        }
        else {
            long long base = pow10(intLength / 2);
            long long high = n / base / 10;
            long long low = n % base;
            int ans = 0;
            ans += (high - base / 10) * 10;
            ans += (n / base) % 10;            
            if (low >= reverse(high)) {
                ++ans;
            }

            return ans;
        }
    }

    static long long pow10(int y) {
        long long ans = 1;
        while (y > 0) {
            ans *= 10;
            --y;
        }

        return ans;
    }

    static long long reverse(long long n) {
        long long ans = 0;
        while (n > 0) {
            ans = (ans * 10) + (n % 10);
            n /= 10;
        }

        return ans;
    }
};

TEST(&Solution::kthPalindrome)