/*
 * @Author: sanjusss
 * @Date: 2022-04-10 12:36:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-10 12:38:55
 * @FilePath: \0\800\800\804.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> morse = { ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                                              ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                                              "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.." };
        unordered_set<string> reps;
        for (auto& w : words) {
            string r;
            for (char i : w) {
                r += morse[i - 'a'];
            }

            reps.insert(r);
        }

        return reps.size();
    }
};