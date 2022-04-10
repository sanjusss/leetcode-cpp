/*
 * @Author: sanjusss
 * @Date: 2022-04-10 10:28:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-10 10:37:19
 * @FilePath: \C\C200\C280\C288\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestInteger(int num) {
        vector<int> bits;
        while (num > 0) {
            bits.push_back(num % 10);
            num /= 10;
        }

        reverse(bits.begin(), bits.end());
        vector<int> odds;
        vector<int> evens;
        int n = bits.size();
        for (int i = 0; i < n; ++i) {
            if (bits[i] % 2 == 0) {
                evens.push_back(i);
            }
            else {
                odds.push_back(i);
            }
        }

        sort(odds.begin(), odds.end(), [&bits](int a, int b) {
            return bits[a] > bits[b];
        });

        sort(evens.begin(), evens.end(), [&bits](int a, int b) {
            return bits[a] > bits[b];
        });
        int oddi = 0;
        int eveni = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans *= 10;
            if (bits[i] % 2 == 0) {
                ans += bits[evens[eveni++]];
            }
            else {
                ans += bits[odds[oddi++]];
            }
        }

        return ans;
    }
};