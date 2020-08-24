#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool repeatedSubstringPattern(string s) {
//        string_view text = s;
//        int size = text.size();
//        for (int i = 1; i <= size / 2; ++i) {
//            if (size % i != 0) {
//                continue;
//            }
//
//            string_view sub = text.substr(0, i);
//            bool success = true;
//            for (int j = i; j < size; j += i) {
//                if (sub != text.substr(j, i)) {
//                    success = false;
//                    break;
//                }
//            }
//
//            if (success) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};