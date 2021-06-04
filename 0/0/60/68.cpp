/*
 * @Author: sanjusss
 * @Date: 2021-06-05 07:03:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-05 07:48:25
 * @FilePath: \0\0\60\68.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        pair<int, int> currentIndex = { 0, 0 };
        int currentLength = 0;

        auto mid = [&ans, &words, &currentIndex, &currentLength, maxWidth]() {  //中对齐
            string line;
            line.reserve(maxWidth);
            int count = currentIndex.second - currentIndex.first;
            int minSpace = (maxWidth - currentLength) / count;
            int oneSpace = (maxWidth - currentLength) % count;
            line += words[currentIndex.first];
            for (int i = 0; i < count; ++i) {
                for (int j = 0; j < minSpace; ++j) {
                    line.push_back(' ');
                }

                if (i < oneSpace) {
                    line.push_back(' ');
                }

                line += words[currentIndex.first + 1 + i];
            }

            ans.push_back(move(line));
            currentIndex = { currentIndex.second + 1, currentIndex.second + 1 };
            currentLength = 0;
        };
        auto left = [&ans, &words, &currentIndex, &currentLength, maxWidth]() {  //左对齐
            string line;
            line.reserve(maxWidth);
            line += words[currentIndex.first];
            for (int i = currentIndex.first + 1; i <= currentIndex.second; ++i) {
                line.push_back(' ');
                line += words[i];
            }

            while (line.size() < maxWidth) {
                line.push_back(' ');
            }

            ans.push_back(move(line));
            currentIndex = { currentIndex.second + 1, currentIndex.second + 1 };
            currentLength = 0;
        };
        
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && currentLength + words[i].size() + currentIndex.second - currentIndex.first + 1> maxWidth) {
                if (currentIndex.first == currentIndex.second) {
                    left();
                }
                else {
                    mid();
                }
            }

            currentIndex.second = i;
            currentLength += words[i].size();
            if (i == n - 1) {
                left();
            }
        }

        return ans;
    }
};

TEST(&Solution::fullJustify)