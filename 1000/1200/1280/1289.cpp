#include "leetcode.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> pre1 = { 0, -1 }; 
        pair<int, int> pre2 = { 0, -1 };
        for (auto& r : grid) {
            pair<int, int> cur1 = { INT_MAX, -1 };
            pair<int, int> cur2 = { INT_MAX, -1 };
            for (int i = 0; i < n; ++i) {
                int sum = (pre1.second == i ? pre2.first : pre1.first) + r[i];
                if (cur1.first > sum) {
                    cur2 = cur1;
                    cur1.first = sum;
                    cur1.second = i;
                }
                else if (cur2.first > sum) {
                    cur2.first = sum;
                    cur2.second = i;
                }
            }

            pre1 = cur1;
            pre2 = cur2;
        }

        return pre1.first;
    }
};