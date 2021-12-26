/*
 * @Author: sanjusss
 * @Date: 2021-12-26 10:25:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-26 11:19:07
 * @FilePath: \C\C200\C270\C273\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        auto arr = nums;
        sort(arr.begin(), arr.end());
        int m = arr.size();
        vector<bool> mark(m);
        vector<int> ans;
        for (int i = 1; i < m; ++i) {
            if (arr[i] == arr[i - 1] || (arr[i] - arr[0]) % 2 != 0) {
                continue;
            }

            ans.clear();
            fill(mark.begin(), mark.end(), false);
            mark[0] = true;
            mark[i] = true;
            bool success = true;
            int k = (arr[i] - arr[0]) / 2;
            ans.push_back(arr[0] + k);
            int fast = i;
            for (int j = 1; j < m; ++j) {
                if (mark[j]) {
                    continue;
                }

                bool find = false;
                while (fast < m) {
                    if (!mark[fast] && arr[fast] - k * 2 == arr[j]) {
                        mark[fast] = true;
                        find = true;
                        break;
                    }
                    else {
                        ++fast;
                    }
                }

                if (find) {
                    ans.push_back(arr[j] + k);
                }
                else {
                    success = false;
                    break;
                }
            }

            if (success) {
                break;
            }
        }

        return ans;
    }
};