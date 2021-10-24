/*
 * @Author: sanjusss
 * @Date: 2021-10-24 10:32:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-24 10:43:26
 * @FilePath: \C\C200\C260\C264\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countValidWords(string sentence) {
        static const auto isValid = [](string_view s) -> bool {
            if (s.empty()) {
                return false;
            }

            switch (s.back()) {
                case '!':
                case '.':
                case ',':
                    s.remove_suffix(1);
                    break;

                default:
                    break;
            }

            bool a = false;
            bool mid = false;
            for (char i : s) {
                if (isalpha(i)) {
                    a = true;
                }
                else if (i == '-') {
                    if (mid || !a) {
                        return false;
                    }

                    mid = true;
                    a = false;
                }
                else {
                    return false;
                }
            }

            if (mid) {
                return a;
            }
            else {
                return true;
            }
        };

        int n = sentence.size();
        int ans = 0;
        int start = 0;
        string_view s = sentence;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (i != start && isValid(s.substr(start, i - start))) {
                    ++ans;
                }

                start = i + 1;
            }
        }

        return ans;
    }
};