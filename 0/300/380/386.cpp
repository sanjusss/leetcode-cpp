/*
 * @Author: sanjusss
 * @Date: 2022-04-18 08:48:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-18 09:19:35
 * @FilePath: \0\300\380\386.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int i = 1;
        while (i <= n) {
            ans.push_back(i);
            if (i * 10 <= n) {
                i *= 10;
            }
            else {
                while (i % 10 == 9 || i + 1 > n) {
                    i /= 10;
                }

                if (i == 0) {
                    break;
                }
                else {
                    ++i;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::lexicalOrder)