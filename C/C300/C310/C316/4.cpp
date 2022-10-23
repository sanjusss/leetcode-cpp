/*
 * @Author: sanjusss
 * @Date: 2022-10-23 10:24:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-23 11:08:51
 * @FilePath: \C\C300\C310\C316\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> oddSrc;
        vector<int> evenSrc;
        for (int i : nums) {
            if (i % 2 == 0) {
                evenSrc.push_back(i);
            }
            else {
                oddSrc.push_back(i);
            }
        }

        vector<int> oddDes;
        vector<int> evenDes;
        for (int i : target) {
            if (i % 2 == 0) {
                evenDes.push_back(i);
            }
            else {
                oddDes.push_back(i);
            }
        }

        sort(oddSrc.begin(), oddSrc.end());
        sort(evenSrc.begin(), evenSrc.end());
        sort(oddDes.begin(), oddDes.end());
        sort(evenDes.begin(), evenDes.end());

        int64_t ans = 0;
        
        int oddN = oddSrc.size();
        for (int i = 0; i < oddN; ++i) {
            ans += abs(oddSrc[i] - oddDes[i]) / 2;
        }

        int evenN = evenSrc.size();
        for (int i = 0; i < evenN; ++i) {
            ans += abs(evenSrc[i] - evenDes[i]) / 2;
        }

        return ans / 2;
    }
};