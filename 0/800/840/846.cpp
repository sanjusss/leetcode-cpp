/*
 * @Author: sanjusss
 * @Date: 2021-12-30 09:57:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-30 10:01:45
 * @FilePath: \0\800\840\846.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1) {
            return true;
        }
        else if (hand.size() % groupSize != 0) {
            return false;
        }

        multiset<int> s(hand.begin(), hand.end());
        while (!s.empty()) {
            int cur = *s.begin();
            s.erase(s.begin());
            for (int j = 1; j < groupSize; ++j) {
                auto p = s.find(++cur);
                if (p == s.end()) {
                    return false;
                }
                else {
                    s.erase(p);
                }
            }
        }

        return true;
    }
};