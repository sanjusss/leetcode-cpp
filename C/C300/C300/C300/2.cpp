/*
 * @Author: sanjusss
 * @Date: 2022-07-03 10:37:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 11:03:29
 * @FilePath: \C\C300\C300\C300\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int maxRound = (min(m, n) + 1) / 2;
        for (int r = 0; r < maxRound && head != nullptr; ++r) {
            int buttom = r;
            int left = r;
            int top = m - 1 - r;
            int right = n - 1 - r;
            for (int j = left; j < right && head != nullptr; ++j) {
                ans[buttom][j] = head->val;
                head = head->next;
            }

            for (int i = buttom; i <= top && head != nullptr; ++i) {
                ans[i][right] = head->val;
                head = head->next;
            }

            if (buttom != top) {
                for (int j = right - 1; j >= left && head != nullptr; --j) {
                    ans[top][j] = head->val;
                    head = head->next;
                }
            }

            if (left != right) {
                for (int i = top - 1; i > buttom && head != nullptr; --i) {
                    ans[i][left] = head->val;
                    head = head->next;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::spiralMatrix)