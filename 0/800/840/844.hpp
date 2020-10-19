#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     bool backspaceCompare(string S, string T) {
//         return convertString(S) == convertString(T);
//     }

// private:
//     string convertString(const string& s) {
//         string res;
//         for (char i : s) {
//             if (i == '#') {
//                 if (!res.empty()) {
//                     res.pop_back();
//                 }
//             }
//             else {
//                 res.push_back(i);
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int si = S.size() - 1;
        int ti = T.size() - 1;
        int skipS = 0;
        int skipT = 0;
        while (si >= 0 && ti >= 0) {
            if (S[si] == '#') {
                ++skipS;
                --si;
                continue;
            }
            
            if (skipS > 0) {
                --skipS;
                --si;
                continue;
            }
            if (T[ti] == '#') {
                ++skipT;
                --ti;
                continue;
            }
            
            if (skipT > 0) {
                --skipT;
                --ti;
                continue;
            }

            if (S[si] != T[ti]) {
                return false;
            }

            --si;
            --ti;
        }

        while (si >= 0) {
            if (S[si] == '#') {
                ++skipS;
            }
            else {
                if (skipS > 0) {
                    --skipS;
                }
                else {
                    return false;
                }
            }

            --si;
        }

        while (ti >= 0) {
            if (T[ti] == '#') {
                ++skipT;
            }
            else {
                if (skipT > 0) {
                    --skipT;
                }
                else {
                    return false;
                }
            }

            --ti;
        }

        return true;
    }
};