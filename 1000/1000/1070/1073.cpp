/*
 * @Author: sanjusss
 * @Date: 2023-05-18 08:46:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-18 09:03:44
 * @FilePath: \1000\1000\1070\1073.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        vector<int> ans(max(arr1.size(), arr2.size()) + 2);
        for (int i = 0; i < arr1.size() || i < arr2.size(); ++i) {
            if (i < arr1.size()) {
                ans[i] += arr1[i];
            }

            if (i < arr2.size()) {
                ans[i] += arr2[i];
            }

            if (ans[i] < 2) {
                continue;
            }

            ans[i] -= 2;
            if (ans[i + 1] >= 1) {
                ans[i + 1] -= 1;
            }
            else {
                ans[i + 1] += 1;
                ans[i + 2] += 1;
            }
        }

        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};