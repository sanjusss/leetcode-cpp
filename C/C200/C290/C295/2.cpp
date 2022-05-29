/*
 * @Author: sanjusss
 * @Date: 2022-05-29 10:27:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-29 10:53:37
 * @FilePath: \C\C200\C290\C295\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans;
        int n = sentence.size();
        string cur;
        for (int i = 0; i <= n; ++i) {
            if (i == n || sentence[i] == ' ') {
                bool isPrice = true;
                int64_t price = 0;
                int m = cur.size();
                if (m > 1 && cur[0] == '$') {
                    for (int j = 1; j < m; ++j) {
                        if (cur[j] < '0' || cur[j] > '9') {
                            isPrice = false;
                            break;
                        }
                        else {
                            price = price * 10 + cur[j] - '0';
                        }
                    }
                }
                else {
                    isPrice = false;
                }

                if (isPrice) {
                    price *= 100 - discount;
                    ans.push_back('$');
                    ans += to_string(price / 100);
                    ans.push_back('.');
                    price %= 100;
                    ans.push_back((price / 10) + '0');
                    ans.push_back((price % 10) + '0');
                }
                else {
                    ans += cur;
                }

                cur.clear();
                if (i < n) {
                    ans.push_back(' ');
                }
            }
            else {
                cur.push_back(sentence[i]);
            }
        }

        return ans;
    }
};