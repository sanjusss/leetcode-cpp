/*
 * @Author: sanjusss
 * @Date: 2020-12-27 12:49:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 19:57:58
 * @FilePath: \0\200\200\205_20201227.hpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s2t.find(s[i]) == s2t.end()) {
                if (t2s.find(t[i]) == t2s.end()) {
                    s2t[s[i]] = t[i];
                    t2s[t[i]] = s[i];
                }
                else {
                    return false;
                }
            }
            else {
                if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};