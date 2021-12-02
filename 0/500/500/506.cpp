/*
 * @Author: sanjusss
 * @Date: 2021-12-02 13:31:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-02 13:35:18
 * @FilePath: \0\500\500\506.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> is(score.size());
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&score](int a, int b) {
            return score[a] > score[b];
        });
        vector<string> ans(is.size());
        for (int i = 0; i < is.size(); ++i) {
            if (i == 0) {
                ans[is[i]] = "Gold Medal";
            }
            else if (i == 1) {
                ans[is[i]] = "Silver Medal";
            }
            else if (i == 2) {
                ans[is[i]] = "Bronze Medal";
            }   
            else {
                ans[is[i]] = to_string(i + 1);
            }
        }

        return ans;
    }
};