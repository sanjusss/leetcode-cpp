/*
 * @Author: sanjusss
 * @Date: 2021-09-09 08:24:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-09 09:26:09
 * @FilePath: \0\0\60\68_20210909.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start = 0;
        int len = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (len == 0) {
                start = i;
                len = words[i].size();
            }
            else if (len + words[i].size() + 1 <= maxWidth) {
                len += words[i].size() + 1;
            }
            else {
                string row = words[start];
                int spaceCount = i - start - 1;
                if (spaceCount > 0) {
                    int spaceSize = (maxWidth - len) / spaceCount + 1;
                    int addCount = (maxWidth - len) - (spaceSize - 1) * spaceCount;
                    for (int j = start + 1; j < i; ++j) {
                        for (int k = 0; k < spaceSize; ++k) {
                            row.push_back(' ');
                        }

                        if (addCount > 0) {
                            --addCount;
                            row.push_back(' ');
                        }

                        row += words[j];
                    }
                }
                else {
                    for (int j = row.size(); j < maxWidth; ++j) {
                        row.push_back(' ');
                    }
                }

                ans.push_back(move(row));
                start = i;
                len = words[i].size();
            }
        }

        string last;
        for (int i = start; i < words.size(); ++i) {
            last += words[i] + " "s;
        }

        last.pop_back();
        for (int j = last.size(); j < maxWidth; ++j) {
            last.push_back(' ');
        }

        ans.push_back(move(last));
        return ans;
    }
};

TEST(&Solution::fullJustify)