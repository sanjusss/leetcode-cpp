/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-25 11:14:03
 * @FilePath: \C\C300\C350\C351\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&positions] (int a, int b) {
            return positions[a] < positions[b];
        });
        stack<int> rights;
        for (int i : is) {
            if (directions[i] == 'R') {
                rights.push(i);
                continue;
            }

            int& lh = healths[i];
            while (!rights.empty()) {
                int& rh = healths[rights.top()];
                if (lh < rh) {
                    lh = INT_MIN;
                    --rh;
                    break;
                }
                else if (lh == rh) {
                    lh = INT_MIN;
                    rh = INT_MIN;
                    rights.pop();
                    break;
                }
                else {
                    --lh;
                    rh = INT_MIN;
                    rights.pop();
                }
            }
        }

        vector<int> ans;
        for (int h : healths) {
            if (h != INT_MIN) {
                ans.push_back(h);
            } 
        }

        return ans;
    }
};