#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int countSubstrings(string s) {
//        string_view sv = s;
//        int size = sv.size();
//        int ans = 0;
//        for (int i = 0; i < size; ++i) {
//            ++ans;
//            for (int j = i + 1; j < size; ++j) {
//                if (isPalindromic(sv.substr(i, j - i + 1))) {
//                    ++ans;
//                }
//            }
//        }
//
//        return ans;
//    }
//
//private:
//    bool isPalindromic(string_view s) {
//        if (m_counts.find(s) != m_counts.end()) {
//            return m_counts[s];
//        }
//
//        int i = 0;
//        int j = s.size() - 1;
//        bool success = true;
//        while (i < j) {
//            if (s[i] != s[j]) {
//                success = false;
//                break;
//            }
//            else {
//                ++i;
//                --j;
//            }
//        }
//
//        m_counts[s] = success;
//        return success;
//    }
//
//private:
//    unordered_map<string_view, bool> m_counts;
//};

class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            ++ans;
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < size && s[l] == s[r]) {
                ++ans;
                --l;
                ++r;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < size && s[l] == s[r]) {
                ++ans;
                --l;
                ++r;
            }
        }

        return ans;
    }
};