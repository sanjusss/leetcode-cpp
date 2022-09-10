/*
 * @Author: sanjusss
 * @Date: 2022-09-07 08:45:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-07 08:57:11
 * @FilePath: \1000\1500\1590\1592.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reorderSpaces(string text) {
        int wordCnt = 0;
        int spaceCnt = 0;
        bool inWord = false;
        for (char i : text) {
            if (i == ' ') {
                ++spaceCnt;
                inWord = false;
            }
            else if (inWord == false) {
                ++wordCnt;
                inWord = true;
            }
        }

        int interval = spaceCnt / max(wordCnt - 1, 1);
        string ans;
        inWord = false;
        for (char i : text) {
            if (i == ' ') {
                if (inWord) {
                    for (int j = 0; j < interval && ans.size() < text.size(); ++j) {
                        ans.push_back(' ');
                    }
                }

                inWord = false;
            }
            else {
                inWord = true;
                ans.push_back(i);
            }
        }

        while (ans.size() < text.size()) {
            ans.push_back(' ');
        }

        return ans;
    }
};