/*
 * @Author: sanjusss
 * @Date: 2021-06-19 15:00:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-19 15:10:22
 * @FilePath: \ms\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        unordered_map<int, int> cnt;
        for (int i : questions) {
            ++cnt[i];
        }

        vector<int> orders;
        for (auto& [_, c] : cnt) {
            orders.push_back(c);
        }

        sort(orders.rbegin(), orders.rend());
        int n = questions.size() / 2;
        int ans = 0;
        for (int c : orders) {
            n -= c;
            ++ans;
            if (n <= 0) {
                break;
            }
        }

        return ans;
    }
};