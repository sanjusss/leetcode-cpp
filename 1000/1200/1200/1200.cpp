/*
 * @Author: sanjusss
 * @Date: 2022-07-04 07:50:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-04 07:54:06
 * @FilePath: \1000\1200\1200\1200.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        int diff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] <= diff) {
                if (arr[i] - arr[i - 1] < diff) {
                    diff = arr[i] - arr[i - 1];
                    ans.clear();
                }

                ans.push_back({ { arr[i - 1], arr[i] } });
            }
        }

        return ans;
    }
};