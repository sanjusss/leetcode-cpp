/*
 * @Author: sanjusss
 * @Date: 2022-04-21 08:39:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-21 08:47:50
 * @FilePath: \0\800\820\824.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string toGoatLatin(string sentence) {
        static const unordered_set<char> vowels = {
            'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U',
        };
        int n = sentence.size();
        string ans;
        int wordCnt = 0;
        char begin = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || sentence[i] == ' ') {
                if (!vowels.count(begin)) {
                    ans.push_back(begin);
                }

                begin = 0;
                ans += "ma";
                ++wordCnt;
                for (int j = 0; j < wordCnt; ++j) {
                    ans.push_back('a');
                }
            }
            else {
                if (begin == 0) {
                    if (!ans.empty()) {
                        ans.push_back(' ');
                    }

                    begin = sentence[i];
                    if (vowels.count(begin)) {
                        ans.push_back(begin);
                    }
                }
                else {
                    ans.push_back(sentence[i]);
                }
            }
        }

        return ans;
    }
};