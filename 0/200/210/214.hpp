#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    string shortestPalindrome(string s) {
//        if (s.empty()) {
//            return s;
//        }
//
//        int size = s.size();
//        int rightEnd = 1;
//        for (int i = size - 1; i > 0; --i) {
//            if (isPalindrome(s, 0, i)) {
//                rightEnd = i + 1;
//                break;
//            }
//        }
//
//        string ans = s.substr(rightEnd) + s;
//        reverse(ans.begin(), ans.begin() + (size - rightEnd));
//        return ans;
//    }
//
//private:
//    bool isPalindrome(string& s, int left, int right) {
//        while (left < right) {
//            if (s[left] == s[right]) {
//                ++left;
//                --right;
//            }
//            else {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size));
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true;
        }

        for (int i = size - 1; i >= 0; --i) {
            for (int j = 0; j < size; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1]);
            }
        }

        int rightEnd = 1;
        for (int i = size - 1; i >= 0; --i) {
            if (dp[0][i]) {
                rightEnd = i + 1;
                break;
            }
        }

        string ans = s.substr(rightEnd) + s;
        reverse(ans.begin(), ans.begin() + (size - rightEnd));
        return ans;
    }
};